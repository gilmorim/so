/**
 * 
 * @file	10proc_v3.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-07-03
 * @brief	Create 10 processes hierarchically. Each child process creates its own child process, and waits for it to complete.
 *          After the last process is done, they all exit in opposite order they were created.
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './10proc_v3'
 */ 

#include <stdio.h>      /* For printf() */
#include <unistd.h>     /* For fork(), _exit(), getpid() */
#include <sys/wait.h>   /* For wait(), WEXITSTATUS() */

#define PROCESSES_NUMBER 10 /* Define how many processes will be created */

int main(){

    printf("I am parent process, and I will start creating child processes\n");

    /** 
     * For loop from 1 to 11 (so we get order starting from 1 instead of 0), where the parent will fork().
     * It will not wait for children to finish before creating more processes, it will just create 10.
     * When the child finishes, it passes the parent a value. The parent will then print out the value passed.
     */
    int processes_created = 1;
    int pid = 0;
    while(processes_created != PROCESSES_NUMBER + 1){
        if(pid < 0){
            perror("fork()");
            _exit(-1);
        }

        if(pid == 0){
            printf("I am a new process, with pid %d, and order: %d. My father is %d.\n", getpid(), processes_created, getppid());
            processes_created++;
            pid = fork();
        } else {
            wait(0);
            printf("I am process %d. My son of pid %d just finished\n", getpid(), pid);
            _exit(0);
        }
    }

    return 0;
}
