// Darnell James Estrada
// Professor Hank Stalica
// CS 3560 SEC 01

// hw01.c

#include "stdio.h"
#include "stdlib.h"

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("prec CHAR ROWS COLS\n");
		exit(0);
	}
	int i, j;
	for (i = 0; i < atoi(argv[2]); i++)
	{
		for (j = 0; j < atoi(argv[3]); j++)
			printf("%s", argv[1]);
		printf("\n");
	}
}
