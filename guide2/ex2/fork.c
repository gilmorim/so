/**
 * 
 * @file	fork.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-06-29
 * @brief	Main process creates a child process. Then, both of them print their PIDs and their parent's PIDs as well.
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './fork'
 * 
 */ 


#include <stdio.h>      /* For printf() */
#include <unistd.h>     /* For fork(), _exit(), getpid() and getppid() */
#include <sys/wait.h>   /* For wait() */

int main(){
    
    int pid;
    pid = fork();

    /**
     *
     * When a process calls fork(), another process exactly equal is created (except for a few things like PID, memory locks...).
     * This new process is called a "child" process, and the process that initially called fork() is the "parent".
     * The most important, and difficult, thing to grasp is the following:
     * 
     * FORK() RETURNS A VALUE (an "int"). HOWEVER, ITS VALUE ON THE PARENT PROCESS AND CHILD PROCESS ARE DIFFERENT
     * 
     * fork() returns 0 to the child (and this value is stored in the variable "pid")
     * fork() returns a positive int to the parent process. Its value is the PID of the child process recently spawned 
     * fork() returns -1 if something bad happened, and could not create a new process.
     * 
     * One last piece of advice: don't read this code sequentially, it does not run sequentially.
     * It runs CONCURRENTLY. This means that child process code section (inside if pid == 0) is running 
     * exactly at the same time as the parent code (written after that same if).
     * Identify the piece of code meant to be run in the child process, and the piece of code meant to be run 
     * on the parent process, and remember that they run exactly at the same time.
     * 
     */
    if(pid == -1){
        /* Check if fork() was successful */
        perror("fork()");
        _exit(-1);
    }
            
    if(pid == 0){
        /* This code section will run on the child process, so look at it from the childs point of view */
        int child_pid = getpid();           /* Use getpid() to get current process PID */
        int childs_parent_pid = getppid();  /* Use getppid() to get current process' parent PID */
        printf("I'm a child.\nMy PID is: %d.\nMy parent is: %d.\n", child_pid, childs_parent_pid);
        _exit(0);
    } 

    /* This code section will run on the parent process */

    /* Parent waits for child process to finish executing  before finishing himself. 
       Interesting things may happen if you comment line below, and run the program. */
    wait(0);

    /* Remember: look at this part of the code from the parent's point of view. */
    int sons_pid = pid; 
    int parents_pid = getpid();
    int parents_parent_pid = getppid();
    printf("I'm a parent.\nMy PID is: %d.\nMy parent is: %d.\nMy son is: %d.\n", parents_pid, parents_parent_pid, sons_pid);

    return 1;    
}
