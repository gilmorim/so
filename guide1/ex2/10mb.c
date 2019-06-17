/**
 *
 * @file 10mb.c
 * @github https://github.com/gilmorim
 * @author Gilberto Morim <gilgmorim@gmail.com>
 * @date "2019-06-08"
 * @brief Creates a 10 MB sized file, composed exclusively of character 'A', using Linux system calls open() and write()
 * 
 * You can run this program by opening a terminal on the directory the file is, type 'make' (which will compile this source file)
 * and then run './10mb'
 *
 */

#include <stdio.h>
#include <unistd.h> /* For system calls open(), read(), write() */
#include <fcntl.h> /* For O_RDWR | O_CREAT */

#define FILE_SIZE 10 * 1024 * 1024 /* File size specified in bytes, as opposed to megabytes */
#define CHARACTER 'A' /* Character to be inserted in file */

int main(int argc, char* argv[]){

    /**
     * Open a file named "10mb.dat", creates if it does not exist, readable and wriable to, on append mode 
     * Returns a file descriptor to the opened file, stored in variable "fd", with permissions to read and write, no execute 
     */
    int fd = open("10mb.dat", O_CREAT | O_RDWR | O_APPEND, 0666);
    char c = CHARACTER;
    
    /* Write to file the character desired, one byte at a time */
    for(int i = 0; i < FILE_SIZE; i += sizeof(c)){
        write(fd, &c, sizeof(c));
    }

    /* Always close your open files */
    close(fd);

    return 1;    
}