/**
 * 
 * @file	matrix_v2.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-07-03
 * @brief	Searches concurrently through a randomly generated matrix for a target value passed as program argument, and prints out 
 *          in ascending order the lines where target was found.
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './matrix'
 */ 

#include <stdio.h>              /* For printf() */
#include <time.h>               /* For time() */
#include <stdlib.h>             /* For srand(), rand() */

#include <unistd.h>             /* For fork(), _exit() */
#include <sys/wait.h>           /* For waitpid() */

#define NUMBER_LINES    5       /* Define how many lines the matrix has */
#define NUMBER_COLUMNS  30      /* Define how many columns the matrix has */

/**
 * 
 * @brief	Receives an empty matrix, and fills it with positive integers ranging from 1 - 100
 * 
 * @param	An already allocated 2d array of integers
 * 
 * @return	-
 * 
 */ 
void fill_matrix(int** matrix){
    time_t t;
    srand((unsigned) time(&t));

    for(int i = 0; i != NUMBER_LINES; i++){
        for(int j = 0; j != NUMBER_COLUMNS; j++){
            matrix[i][j] = rand()%100 + 1;
        }
    }
}

/**
 * 
 * @brief	Prints out content of a received matrix
 * 
 * @param	The matrix whose content will be printed
 * 
 * @return	-
 * 
 */ 
void print_matrix(int** matrix){
    for(int i = 0; i != NUMBER_LINES; i++){
        for(int j = 0; j != NUMBER_COLUMNS; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv){

    /* Guarantee user introduces target number */
    if(argc < 2){
        printf("not enough arguments\n");
        return(-1);
    }

    /* Retrieve target number from user argument */
    int target_number = atoi(argv[1]);

    /* Allocate space for a 2D array to store the random numbers. If you don't understand it, consider going back to MP2 */
    int** matrix = (int**)malloc(sizeof(int*) * NUMBER_LINES);
    for(int i = 0; i < NUMBER_COLUMNS; i++){
        *(matrix + i) = (int*)malloc(sizeof(int) * NUMBER_LINES);
    } /* Just kidding, I had to google it as well */

    fill_matrix(matrix);
    // print_matrix(matrix);

    /* Create a process for each of the lines (5 in this case). Each process then is gonna search its attributed line, and print
     * out matrix coordinates where it finds the target. Additionally, in order to wait for the processes orderly, it's important
     * that the parent stores the pids of the created processes. That's what the array is there for, it will be used in the 
     * wait() phase.
     */
    int created_processes[NUMBER_LINES];
    for(int i = 0; i != NUMBER_LINES; i++){
        int pid = fork();
        if(pid < 0){
            perror("fork()");
            _exit(-1);
        }

        /* Child processes code section */
        if(pid == 0){
            /* If process finds target, exit with it's order number, if not, exit with zero */
            for(int j = 0; j != NUMBER_COLUMNS; j++){
                if(matrix[i][j] == target_number){
                    // printf("Process %d found target on [%d:%d]\n", getpid(), i, j);
                    _exit(i);
                } 
            }
            _exit(0);
        } else {
            created_processes[i] = pid;
        }
    }

    /* Parent waits for each of the processes to finish, before releasing resources and finishing himself */
    int status = 0;
    for(int k = 0; k != NUMBER_LINES; k++){
        
        /** 
          * Wait for each of the processes, in the same order they were created (instead of waiting for whatever process 
          * finished first). We use waitpid() for that - wait for a specific pid.
          */
        waitpid(created_processes[k], &status, 0);
        if(WEXITSTATUS(status)){
            int process_status = WEXITSTATUS(status);

            /* Only print out processes that found target, aka exited with a value different than zero */
            if(process_status != 0){
                printf("Process #%d found target\n", process_status);
            }
        } 
    }

    free(matrix); /* Always free() your malloc()ed things */
    return 0;
}
