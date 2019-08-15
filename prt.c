// Darnell James Estrada
// Professor Hank Stalica
// CS 3560 SEC 01

// prt.c

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "errno.h"

#define BUFFERSIZE 4096

int main(int argc, char* argv[])
{
	int fd, errsv, length, n_chars;
	char buf[BUFFERSIZE];
	
	if(argc != 2)
	{
		printf("prt FILENAME\n");
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY)) == -1)
	{
		errsv = errno;
		switch(errsv)
		{
			case ENOENT: printf("No such file or directory\n"); break;
			case EACCES: printf("Permission denied\n"); break;
			default: break;
		}
	}
	
	length = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	while((n_chars = read(fd, buf, length)) > 0)
		write(1, buf, n_chars);
	close(fd);

	return 0;
}
