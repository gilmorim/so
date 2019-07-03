/**
 *
 * @file mycat.c
 * @github https://github.com/gilmorim
 * @author Gilberto Morim <gilgmorim@gmail.com>
 * @date "2019-06-08"
 * @brief Repeats everything user types in, using Linux system calls read() and write()
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './mycat'
 *
 */

#include <stdio.h>
#include <unistd.h> /* For system calls open(), read(), write() */

int main(){
    char c; /* Where each character of user input will be stored */
    
    /**
     *
     * Write to standard output (file descriptor 1)
     * everything it can read from standard input (file descriptor 0),
     * which is stored in the 'c' variable;
     *
     */
    while(read(STDIN_FILENO, &c, sizeof(c))){
        write(STDOUT_FILENO, &c, sizeof(c));
    }

    return 1;    
}
