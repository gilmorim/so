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

#include <stdio.h>  /* For perror() */
#include <unistd.h> /* For system calls open(), read(), write() */
#include <stdlib.h> /* For atoi() */

int main(int argc, char* argv[]){

    /* Make sure user input the size of the block of bytes. If not, exit */
    if(argc < 2){
        perror("not enough arguments\n");
        return -1;
    }

    int block_size = atoi(argv[1]); /* Get block size from user input */
    char c[block_size];             /* Assign a buffer to store user input*/

    /**
     *
     * Since read() reads UP TO n bytes (n being the value passed by argument), it could happen that user's text smaller than that.
     * Therefore we have to store the value of bytes that read() reads, and only write() that amount.
     *
     */
    int nbytes = 0;
    
    /**
     *
     * Write to standard output (file descriptor 1)
     * everything it can read from standard input (file descriptor 0),
     * which is stored in the 'c' buffer, of size allocated previously;
     *
     */
    while(nbytes = read(STDIN_FILENO, c, sizeof(c))){
        write(STDOUT_FILENO, c, nbytes);
    }

    return 1;    
}
