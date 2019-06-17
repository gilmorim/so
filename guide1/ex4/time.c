/**
 *
 * No code needed, just run the ex3 program (like in the example) and compare. 
 * The difference is that now we use the 10mb.dat file created in ex2 as input (instead of manually typing stuff).
 * In my case, I ran the following commands (you need to adapt to your system):
 * 
 * $ time ./mycat 1 < ../ex2/10mb.dat > /tmp/lixo
 * Output: real    0m15,118s
           user    0m5,194s
           sys     0m9,881s

 * $ time ./mycat 1024 < ../ex2/10mb.dat > /tmp/lixo
 * Output: real    0m0,029s
           user    0m0,004s
           sys     0m0,026s
 * 
 * The bottom line is that calling read() and write() takes up valuable CPU processing time,
 * so we have to be efficient when we do it. Calling them byte by byte leads to thousands of calls (and thousands
 * of milliseconds of CPU time). Calling them in blocks of 1024 bytes reduces number of read() and write() calls
 * (even though we read and write more bytes at a time), and makes it so much more efficient.
 * 
 * Calling it 1 byte at a time made the program take 15sec to run.
 * Calling it 1024 bytes at a time made the program take less than a second to run.
 * 
 */

