/**
 * 
 * @file	my_system.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-07-11
 * @brief	Emulates system() function
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file) 
 * and then run './my_system'
 * 
 */ 

#include <unistd.h>     /* For execl(), fork() */
#include <sys/wait.h>   /* For _exit() */
#include <stdio.h>      /* For perror() */

int mySystem(char *args){

    /* Check "man system" for the definition. Basically invoke the bash to run the argument passed. */
	if(!fork()){
        execl("/bin/sh","sh","-c",args,NULL);
        perror("fail exec");
        return -1;
	} else {
	    wait(NULL);
	    return 0;
	}
}

int main()
{
	mySystem("ls -l");
}

