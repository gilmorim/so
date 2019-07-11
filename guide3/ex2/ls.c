/**
 * 
 * @file	ls.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-07-11
 * @brief	Runs the "ls -l" command in a child process.
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file) 
 * and then run './ls'
 * 
 */ 

#include <unistd.h>     /* For execlp(), fork(), _exit() */
#include <sys/wait.h>   /* For wait() */
#include <stdio.h>      /* For perror() */

int main(){

    /* Same deal as before, only now in a fork()ed process */
    if(!fork()){
        execlp("ls", "ls", "-l", NULL);
        perror("execlp()");
        _exit(-1);
    }

    wait(NULL);
    return 0;
}
