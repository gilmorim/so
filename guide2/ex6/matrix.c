/**
 * 
 * @file	matrix.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-07-03
 * @brief	Searches concurrently through a randomly generated matrix for a target value passed as program argument.  
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './matrix'
 */ 

#include <stdio.h>              /* For printf() */
#include <time.h>               /* For time() */
#include <stdlib.h>             /* For srand(), rand() */

#include <unistd.h>             /* For fork(), _exit(), getpid() */
#include <sys/wait.h>           /* For wait() */

#define NUMBER_LINES    5      /* Define how many lines the matrix has */
#define NUMBER_COLUMNS  1024    /* Define how many columns the matrix has */

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
     * out matrix coordinates where it finds the target.
     */
    for(int i = 0; i != NUMBER_LINES; i++){
        int pid = fork();

        if(pid < 0){
            perror("fork()");
            _exit(-1);
        }

        /* Child processes code section */
        if(pid == 0){
            for(int j = 0; j != NUMBER_COLUMNS; j++){
                if(matrix[i][j] == target_number){
                    printf("Process %d found target on [%d:%d]\n", getpid(), i, j);
                }
            }
            _exit(0);
        }
    }

    /* Parent waits for each of the processes to finish, before releasing resources and finishing himself */
    for(int k = 0; k != NUMBER_LINES; k++){
        wait(0);
    }

    free(matrix); /* Always free() your malloc()ed things */
    return 0;
}
