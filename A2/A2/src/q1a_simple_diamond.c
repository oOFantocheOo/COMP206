#include <stdio.h>
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX
#include <stdlib.h>  // for strtol


int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf("ERROR: Wrong number of arguments.One required.");
		return -1;
	}
	

	char *p;
	int height;

	errno = 0;
	long conv = strtol(argv[1], &p, 10);

	// Check for errors: e.g., the string does not represent an integer
	// or the integer is larger than int
	if (errno != 0 || *p != '\0' || conv > INT_MAX || conv % 2 != 1) {
		printf("ERROR: Bad argument. Height must be positive odd integer.");
		return -1;
	}
	else {
		// No error
		height = conv;
	}

	int tool = (height + 1) / 2;
	for (int i = 1; i <= height; i++) {
		int blank = abs(tool - i);
		int star = height - 2 * blank;
		for (int j = 0; j < blank; j++)printf(" ");
		for (int j = 0; j < star; j++)printf("*");
		for (int j = 0; j < blank; j++)printf(" ");
		printf("\n");
	}
	

	return 0;
}