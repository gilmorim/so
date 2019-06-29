/**
 * 
 * @file	pid.c
 * @github	https://github.com/gilmorim
 * @author	Gilberto Morim <gilgmorim@gmail.com>
 * @date	2019-06-29
 * @brief	Prints out process ID (PID), and its parent's PID
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './pid'
 * 
 */ 


#include <stdio.h>      /* For printf() */
#include <unistd.h>     /* For getpid() and getppid() */

int main(){
    int my_pid = getpid();          /* Use getpid() to get current process PID */
    int my_parent_pid = getppid();  /* Use getppid() to get current process' parent PID */
    printf("I'm a child.\nMy PID is: %d.\nMy parent is: %d.\n", my_pid, my_parent_pid);
    return 1;    
}