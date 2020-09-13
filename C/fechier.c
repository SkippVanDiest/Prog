#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fd = open("test1.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

    for(int i = 0; i < 4; i++)
    {
        lseek(fd, 10000, SEEK_END);
    }

    close(fd);
    
    exit(EXIT_SUCCESS);
}