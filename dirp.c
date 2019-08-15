// Darnell James Estrada
// Professor Hank Stalica
// CS 3560 SEC 01

// dirp.c

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "unistd.h"
#include "errno.h"

int main(int argc, char* argv[])
{
	int dir;
	int errsv;

	switch(argc)
	{
		case 3: 
		{
			if(strcmp(argv[1], "-c") == 0)
				dir = mkdir(argv[2], 0744);
			else if (strcmp(argv[1], "-d") == 0)
			{
				dir = unlink(argv[2]);
				errsv = errno;

				if (errsv == ENOENT)
					printf("No such file or directory\n");

				dir = rmdir(argv[2]);
				errsv = errno;

				if(errsv == ENOTEMPTY)
					printf("Directory not empty\n");
			}
			else
				printf("dirp OPTION FILE [FILE]\n");
	
			break;
		}
		case 4:
		{
			if(strcmp(argv[1], "-r") == 0)
				dir = rename(argv[2], argv[3]);
			break;
		}
		default:
		{
			printf("dirp OPTION FILE [FILE]\n");
			break;
		}
	}

	exit(1);
}
