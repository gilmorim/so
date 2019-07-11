/**
 * 
 * @file	ls.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-07-11
 * @brief	Runs the "ls -l" command
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file) 
 * and then run './ls'
 * 
 */ 

#include <unistd.h> /* For execlp() */
#include <stdio.h>  /* For perror() */

int main(){

    /** 
     * 
     * Running any exec() will run whatever program you want to, 
     * and will terminate the process. That means that any code you write
     * after the exec() will not be run (unless exec() fails).
     * 
     * Don't ever write meaningful code after an exec() call.
     * 
     * Running execlp() is easier and more convenient, because you don't need to specify the directory of the executable.
     * Running with execl() is also possible, but you would have to use execl("/bin/ls", "ls", "-l", NULL).
     */
    execlp("ls", "ls", "-l", NULL);
    
    /** 
     * This code only runs if exec() fails.
     */
    perror("execlp()");
    return -1;
}
