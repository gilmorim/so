/**
 *
 * @file    readln.c
 * @github  https://github.com/gilmorim
 * @author  Gilberto Morim <gilgmorim@gmail.com>
 * @date    "2019-06-08"
 * @brief   Reads line by line content from a file descriptor, using Linux system calls read() and write()
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './readln < test.txt' (you can also type things manually, but using a file makes it easier to separate 
 * by lines).
 *
 */

#include <unistd.h> /* For system calls read(), write() */

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
    while (read(filedes, &c, sizeof(c))){
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
    
    /**
     *
     * Write to standard output (file descriptor 1) 
     * everything it can read from standard input (file descriptor 0), line by line.
     * Each line is stored in the 'buf' buffer;
     *
     */
    while(nbytes = readln(STDIN_FILENO, &buf, 1)){
        write(STDOUT_FILENO, &buf, nbytes);
    }

    return 1;    
}
