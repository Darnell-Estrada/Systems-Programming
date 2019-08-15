// Darnell James Estrada
// Professor Hank Stalica
// CS 3560 SEC 01

// mytouch.c

#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "sys/time.h"
#include "sys/types.h"
#include "utime.h"
#include "time.h"
#include "errno.h"

int main(int argc, char* argv[])
{
	int fd_exist, fd_make, errno, errsv;
	time_t when;
	struct utimbuf curr;

	if(argc == 2)
	{
		if(fd_exist = open(argv[1], O_CREAT, 0644) == -1)
		{
			errsv = errno;
			if(errsv == ENOENT)
				fd_make = creat(argv[1], 0644);
		}
		else
			utime(argv[1], NULL);
	}
	else if (argc == 3)
	{
		curr.actime = curr.modtime = atoi(argv[2]);
		utime(argv[1], &curr);
	}
	else
	{
		printf("mytouch FILE [SECONDS]\n");
		exit(1);
	}
	return 0;
}
