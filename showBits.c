//Scott Patterson
//4/29/17
//Assignment 2
//Mark Morresy
//This program takes in args from the user represented as hex values and outputs what bits are both 1 in those 2 hex values
//it will then output that new binary number in an unsigned and signed format

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

int main(int argc, char * argv[])
{
	int hexNum1 = 0;
	int hexNum2 = 0;
	int hexBinEqual = 0;
	int sNum = 0;
	unsigned int uNum = 0;

	if(argc != 3)
	{
		printf("Error: Please provide 2 hexadecimal values (ex. 0xFFFFFFFF)\n");
		exit(0);
	}

	//turn our hex values into integers
	hexNum1 = (int)strtol(argv[1], NULL, 0);
	hexNum2 = (int)strtol(argv[2], NULL, 0);
	hexBinEqual = sNum = hexNum1 & hexNum2;
	uNum = hexNum1 & hexNum2;

	printf("Bits turned on: ");

	//using the new integer we got from our & bit comparison, compare with 1 to see which bits are turned on
	for(int i = 0; i < 33; ++i)
	{
		if(hexBinEqual & 1 == 1)
		{
			printf("%d,", i);
		}
		//shift right by 1 bit
		hexBinEqual = hexBinEqual >> 1;
	}

	//print out the hex representation, signed representation, and unsigned representation
	printf(" Hexadecimal: %x, Signed: %d, Unsigned: %u\n", sNum, sNum, uNum);

	exit(0);
}

