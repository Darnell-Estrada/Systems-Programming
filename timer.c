// Darnell James Estrada
// Professor Hank Stalica
// CS 3560 SEC 01

// timer.c

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "termios.h"

int main(int argc, char* argv[])
{
	int temp_int;
	static struct termios reset;
	struct termios countdown;

	tcgetattr(0, &reset);

	if(argc == 2)
	{
		temp_int = atoi(argv[1]) + 1;
	
		tcgetattr(0, &countdown);
		countdown.c_lflag &= ~ECHO;
		countdown.c_cc[VSTART] = 'u';
		countdown.c_cc[VSTOP] = 'p';
		tcsetattr(0, TCSANOW, &countdown);

		while (temp_int--)
		{
			printf("%i\n", temp_int);
			sleep(1);
		}
	}	
	else
	{
		printf("timer seconds\n");
	}
	
	tcsetattr(0, TCSANOW, &reset);

	exit(1);
}
