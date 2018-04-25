//
// Created by avishay on 08/04/15.
// this class is for task 1.8 creating a user space program - "read"
// this program will read user input (character by character), from the
// standard input, and will print the characters to the standard output. read will terminate when the
// ‘q’ character will be read.
//

#include "types.h"
#include "stat.h"
#include "user.h"


char buf[512];

int main(int argc, char *argv[])
{
    int n;
    while((n = read(0,buf,1)>0) && (*buf != 'q'))
    {
        write(1, buf, n);
    }
    while (n>0)
    {
        n = read(0,buf,1);
        if (*buf == '\n')
            break;
    }
    if(n < 0) {
        printf(1, "read: got a read error\n");
        exit(0);
    }
    write(1,(void*)"\n",1);
    exit(0);
}