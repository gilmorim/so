/**
 * 
 * @file	args.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-07-11
 * @brief	Prints out the received arguments
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file) 
 * and then run './args'
 * 
 */ 

#include <unistd.h>     /* For execlp(), fork(), _exit() */
#include <sys/wait.h>   /* For wait() */
#include <stdio.h>      /* For perror() */

int main(int argc, char** argv){
    
    if(argc < 1){
        printf("no arguments.\n");
        return 1;
    }

    for(int i = 0; i != argc; i++){
        printf("%d\t%s\n", i, argv[i]);
    }

    return 0;
}
