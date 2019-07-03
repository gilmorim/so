/**
 * 
 * @file	10proc.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-06-29
 * @brief	Creates 10 processes sequentially, each of them printing their PID. Parent waits for each of them, printing
 *          their exit value
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './10proc'
 * 
 */ 


#include <stdio.h>      /* For printf() */
#include <unistd.h>     /* For fork(), _exit(), getpid() */
#include <sys/wait.h>   /* For wait(), WEXITSTATUS() */

#define PROCESSES_NUMBER 10 /* Define how many processes will be created */

int main(){

    printf("I am parent process, and I will start creating child processes\n");

    /** 
     * For loop from 1 to 11 (so we get order starting from 1 instead of 0), where the parent will fork()
     * each loop, and wait for the child to finish executing, before creating another one.
     * When the child finishes, it passes the parent a value. The parent will then print out the value passed
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
        } else {
            int status = 0;
            wait(&status); /* Wait for child to finish */
            printf("I am parent, and my child of order %d just exited\n", WEXITSTATUS(status)); /* WEXITSTATUS() to retrieve exit value */
        }
    }
    return 0;   
}
