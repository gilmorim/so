/**
 *
 * @file    nl.c
 * @github  https://github.com/gilmorim
 * @author  Gilberto Morim <gilgmorim@gmail.com>
 * @date    "2019-06-08"
 * @brief   Reads line by line content from a file descriptor, using Linux system calls read() and write(), numbering each line
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './nl' (which will start reading from user input), or './nl [WHATEVER FILE TO READ]' (will read a file).
 *
 */

#include <unistd.h> /* For system calls read(), write(), open() */
#include <fcntl.h>  /* For O_RDONLY */
#include <stdio.h>  /* For printf() and sprintf() */
#include <string.h> /* For strcat() */

/**
 *
 * This function follows the same prototype as read(). It reads character by character until it finds '\n' (which
 * symbolizes end of line), places whatever it reads on the buf parameter, and returns amount of bytes read (
 * including new line character)
 * 
 * @param filedes   File descriptor of the file to be read
 * @param buf       Buffer where line read will be stored
 * @param nbyte     How many bytes will be read at once (kinda useless in this case, since it is always 1)
 * 
 * @return          Number of bytes read 
 * 
 */
ssize_t readln(int filedes, void* buf, size_t nbyte){

    char c;                         /* Variable where each byte is temporarily stored */
    char* aux_buffer = (char*)buf;  /* Cast of the buf param to a string */
    int bytes_read = 0;             /* Variable where amount of bytes read will be stored */
    
    /**
     *
     * Read from filedes and stores it in buffer until it finds 'newline' character ('\n'). 
     * If it finds it, return amout of bytes read 
     *
     */
    while (read(filedes, &c, nbyte)){
        aux_buffer[bytes_read] = c;
        if(c == '\n'){
            return bytes_read+1;
        } else {
            bytes_read++;
        }
    }
    return bytes_read;
}

int main(int argc, char* argv[]){

    char buf[256];                  /* Assign a buffer to store user input*/
    int nbytes = 0;                 /* Bytes returned from readln() */
    int lines_read = 1;             /* Amount of lines read, starting at 1 */
    int fd = 0;                     /* File descriptor from where to read */

    /**
     *
     * Where to read from. If there are no arguments (i.e argc == 1), read from stdin
     * If there are arguments (argc > 1), open the file for reading only, and read from it
     *
     */
    if (argc == 1){
        fd = STDIN_FILENO;
    } else{

        /* Check if file exists */
        if ((fd = open(argv[1], O_RDONLY)) < 0){
            perror(argv[1]);
            return -1;
        } 
    }
    
    

    /**
     *
     * Write to standard output (file descriptor 1) 
     * everything it can read from input, line by line, where each line is numbered.
     *
     */
    while((nbytes = readln(fd, &buf, 1)) > 0){
        char output[256];                   /* String where program output is created */
        buf[nbytes-1] = '\0';               /* Strings coming from read() are not null terminated, gotta do that manually */
        sprintf(output, "%d ", lines_read); /* Using sprintf() to prefix the output with line number and whitespace */
        strcat(output, buf);                /* Concatenate prefix and line */
        
        printf("%s\n", output);             /* And print */
        lines_read++;                       /* Next line number */
    }

    if(fd > 2) close (fd);                  /* Always close your open() files */

    return 1;    
}