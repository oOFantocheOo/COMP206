#include <stdio.h>
#include <errno.h>
#include <limits.h>  
#include <stdlib.h>  


void print_row(int r, int h, int l)
{
	int star = 2 * r - 1;
	int blank = (h*2-1-star)/2;
	int space = h / 2;
	if (l == 1) {

		for (int j = 0; j < blank; j++)printf(" ");
		for (int j = 0; j < star; j++)printf("*");
		for (int j = 0; j < blank; j++)printf(" ");
	}
	else if (r <= h / 2) {
		for (int j = 0; j < space; j++)printf(" ");
		print_row(r, h / 2, l - 1);
		for (int j = 0; j < space; j++)printf(" ");
	}
	else {
		print_row(r - h / 2, h / 2, l - 1);
		printf(" ");
		print_row(r - h / 2, h / 2, l - 1);
	}
	return;
}


int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("ERROR: Wrong number of arguments.Two required.");
		return -1;
	}
	

	char *p1;
	char *p2;
	
	errno = 0;
	long conv1 = strtol(argv[1], &p1, 10);
	long conv2 = strtol(argv[2], &p2, 10);

	if (errno != 0 || *p1 != '\0' || conv1 > INT_MAX || conv1 % 2 != 1) 
	{
		printf("ERROR: Bad argument. Height must be positive odd integer.");
		return -1;
	}
	int H = conv1;

	if (errno != 0 || *p2 != '\0' || conv2 > INT_MAX || conv2<=0)
	{
		printf("ERROR: Height does not allow evenly dividing requested number of levels.");
		return -1;
	}



	if (H == 1 && conv2 == 1)
	{
		printf("*\n");
		return 0;
	}
	int tri_height = (H + 1) / 2;
	int maxHeight = 1;
	for (int i = 0; i < conv2 - 1; i++)
		maxHeight *= 2;
	if (tri_height < maxHeight) 
	{
		printf("ERROR: Height does not allow evenly dividing requested number of levels.");
		return -1;
	}
	int tmp = 2;
	for (tmp; tmp < tri_height; tmp *= 2);
	if (tmp != tri_height) {
		printf("ERROR: Height does not allow evenly dividing requested number of levels.");
		return -1;
	}
	int L = conv2; 

	for (int i = 1; i <= tri_height; i++) {
		print_row(i, tri_height, L);
		printf("\n");
	}
	for (int i = tri_height - 1; i >= 1; i--) {
		print_row(i, tri_height, L);
		printf("\n");
	}
	return 0;
}

