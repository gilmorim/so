/**
 * 
 * @file	10proc_v2.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-07-03
 * @brief	Create and wait for 10 processes CONCURRENTLY. Processes may be created and finish at random orders.
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './10proc_v2'
 */ 

#include <stdio.h>      /* For printf() */
#include <unistd.h>     /* For fork(), _exit(), getpid() */
#include <sys/wait.h>   /* For wait(), WEXITSTATUS(), WIFEXITED()*/

#define PROCESSES_NUMBER 10 /* Define how many processes will be created */

int main(){

    printf("I am parent process, and I will start creating child processes\n");

    /** 
     * For loop from 1 to 11 (so we get order starting from 1 instead of 0), where the parent will fork().
     * It will not wait for children to finish before creating more processes, it will just create 10.
     * When the child finishes, it passes the parent a value. The parent will then print out the value passed.
     */
    for(int i = 1; i != PROCESSES_NUMBER + 1; i++){
        int pid = fork();

        /* Check for fork() errors */
        if(pid < 0){
            perror("fork()");
            _exit(-1);
        }

        /* Child process code */
        if(pid == 0){
            int pid = getpid();
            printf("I am child number %d, and my process number is %d\n", i, pid);
            _exit(i); /* When the child process finishes, it passes its order number through _exit() */
        }
    }

    /** 
     * Parent process code.
     * Loop to wait for children to finish, in whatever order the Linux scheduler decides to finish the process.
     * Just run the program to witness the chaos. 
     */
    for(int i = 0; i != PROCESSES_NUMBER; i++){
        int status = 0;
        wait(&status);
        
        /* Check if process terminated normally */
        if(WIFEXITED(status)){
            printf("I am parent, and my child of order %d just exited\n", WEXITSTATUS(status)); /* WEXITSTATUS() to retrieve exit value */
        }
    }

    return 0;   
}
