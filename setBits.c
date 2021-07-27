//Scott Patterson
//4/29/17
//Assignment 2
//Mark Morresy
//This program takes in args from the user and turns on those bits in the binary representation of the number

#include <stdio.h>
#include <stdlib.h>

//prototypes
void shortToBinary(unsigned short num, int count);
int powTwo(int base, int exp);

//main function that hold arguements passed in, argv[0] contains the name of our program
int main(int argc, char * argv[])
{
	unsigned short num = 0;

	//checks to see if we have the right number of arguments
	if(argc < 1 || argc > 17)
	{
		printf("Too many or too few arguments!\n");
		exit(0);
	}
	
	//check to see if the arguments are in the proper range
	for(int i = 1; i < argc; ++i)
	{
		if(atoi(argv[i]) < 0 || atoi(argv[i]) > 15)
		{
			printf("Arguments too big or small (0-15)\n");
			exit(0);
		}
	}

	//compute the number
	for(int i = 1; i < argc; ++i)
	{
		num += powTwo(2, atoi(argv[i]));
	}
		
	printf("The decimal is %d and the binary is ", num);

	//convert to binary
	shortToBinary(num, 0);
	exit(0);
}

//recursive function to print out the binary representation of an unsigned short
void shortToBinary(unsigned short num, int count)
{
	unsigned short bNum = 0;
	
	if(count > 15)
	{
		return;
	}

	bNum = num & 1;
	shortToBinary(num >> 1, ++count);
	printf("%d", bNum);
}

//function to compute powers and return an int
int powTwo(int base, int exp)
{
	int val = 1;

	if(exp == 0)
	{
		return 1;
	}
	else if(exp == 1)
	{
		return base;
	}
	else
	{
		for(int i = 0; i < exp; ++i)
		{
			val = val * base;
		}
	}
	return val;
}
