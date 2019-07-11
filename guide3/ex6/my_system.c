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
#include <string.h>
#include <stdlib.h>

#define MAX_ARG_LEN	1024

int my_system(char *args){
	int ind_arg = 0;
	char* token;

	// char* arr_args[MAX_ARG_LEN];

	token = strtok(args, " ");
	
	while(token != NULL){
		
		ind_arg++;

		printf("token %d: %s\n", ind_arg, token);
		token = strtok(NULL, " ");
	}

	// execvp(arr_args[0], arr_args);
	return -1;
}

int main(){
	my_system("ls -l");
	return 0;
}

