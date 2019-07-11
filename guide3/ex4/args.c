/**
 * 
 * @file	args.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-07-11
 * @brief	Runs ex3 program, with whatever arguments you pass
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file) 
 * and then run './args'
 * 
 */ 

#include <unistd.h>     /* For execlp() */
#include <stdio.h>      /* For perror() */

int main(){

    execl("../ex3/args", "args" /* try changing this one for something else */, "one", "two", "three", "four", "five", NULL);
    perror("execl()");
    return -1;
}
