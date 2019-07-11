/**
 * 
 * @file	execs.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-07-11
 * @brief	Runs ex3 program, with whatever arguments you pass
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file) 
 * and then run './execs'
 * 
 */ 

#include <unistd.h>     /* For execl(), fork() */
#include <sys/wait.h>   /* For _exit() */
#include <stdio.h>      /* For perror() */

int main(int argc, char** argv){

    /* Check for arguments */
    if(argc < 2){
        printf("no arguments.\n");
        return 0;
    }

    /* Make a process for each argument (program), and run it there. We start at 1 because argv[0] is "./execs". We don't want that one. */
    for(int i = 1; i != argc; i++){
       if(!fork()){
           execlp(argv[i], argv[i], NULL);
           perror("exec()");
           _exit(-1);
       } 
    }

    /* Wait for them to finish */
    for(int j = 1; j != argc; j++){
        wait(NULL);
    }
    
    return -1;
}
