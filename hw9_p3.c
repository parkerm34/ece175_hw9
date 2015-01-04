/* 	Author: Parker Mathewson
 *	Date: 4/8/12
 *	Comments: Program to convert any base to decimal. This will be done using arrays.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int length_of_number(long int number, int base)
{
	int count=0;

	while(number!=0)
	{
		count++;
		number=number/10;
	}
	return count;
}

int binary_to_decimal(long int number, int base)
{
	int decimal=0, i=0, digit=0, len=0;

	for(i=length_of_number(number, base); number!=0; i--)
	{
		digit=number/pow(10, i-1);
		decimal+=digit*pow(base,i-1);
		number=number-(digit*pow(10,i-1));
	}
	return decimal;
}

int main(void)
{
	long int binary;
	int decimal=0, base=0;
	char quit='y';

	printf("Enter the base number you want to convert from: ");
	scanf("%d",&base);
	fflush(stdin);
	printf("Enter the number you want to convert: ");
	scanf("%d",&binary);
	decimal = binary_to_decimal(binary, base);
	printf("Your number is %d in decimal.\n",decimal);

	while(quit != 'q' || quit !='Q')
	{
		printf("Enter Q or q to quit or any other character to enter another number: ");
		scanf("%s",&quit);
		fflush(stdin);
		if(quit == 'Q' || quit == 'q')
			return(0);
		else
		{
			printf("Enter the base you want to convert from: ");
			scanf("%d", &base);
			fflush(stdin);
			printf("Enter the number you want to convert: ");
			scanf("%d",&binary);
			fflush(stdin);
			decimal = binary_to_decimal(binary, base);
			printf("Your number is %d in decimal.\n",decimal);
		}
	}
	return(0);
}
