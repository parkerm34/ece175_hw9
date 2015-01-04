/*	Author: Parker Mathewson								*
 *	Date: 4/8/12										*
 *	Comments: This program is to test the efficiency of the bubble sort and the selection	*
 *			sorts. I will be printing out the number of comparisons made by each.	*/

#include <stdio.h>
#include <stdlib.h>
#define COUNT 30

void swap(int *a, int *b)
{
	int temp=*a;
	*a = *b;
	*b = temp;
}

void bubble_sort_function(int *array_random_numbers)
{
	int comparison_counter=0, loop_counter=0, flag=1;

	while(flag)
	{
		flag=0;
		for(loop_counter=0; loop_counter<COUNT-2; loop_counter++)
		{
			comparison_counter++;
			if(array_random_numbers[loop_counter] > array_random_numbers[loop_counter+1])
			{
				swap(array_random_numbers+loop_counter, array_random_numbers+loop_counter+1);
				flag = 1;
			}
		}
		printf("%d ", comparison_counter);

	}
	printf("\n\n");
}

void selection_sort_function(int *array_random_numbers)
{
	int comparison_counter=0, loop_counter=0, j, *min, min_nonptr;

	min = &min_nonptr;

	for(loop_counter=0; loop_counter<COUNT; loop_counter++)
	{
		*min = array_random_numbers[loop_counter];
		for(j=loop_counter; j<COUNT;j++)
		{
			comparison_counter++;
			if(*(array_random_numbers+j)<*min)
				*min = array_random_numbers[j];
		}
		swap(min, array_random_numbers+loop_counter);
		printf("%d ", comparison_counter);
	}
	printf("\n\n\n");
}

void array_init(int array_random_numbers[COUNT], int dependency)
{
	int counter=0;

	if(dependency == 0 || dependency == 1)
	{
		for(counter=0; counter<COUNT; counter++)
			array_random_numbers[counter]=random();
		if(dependency == 0)
			selection_sort_function(array_random_numbers);
		else
			bubble_sort_function(array_random_numbers);
	}

	else if(dependency == 2 || dependency ==3)
	{
		for(counter=0; counter<COUNT; counter++)
			array_random_numbers[counter]=counter;

		if(dependency == 2)
			selection_sort_function(array_random_numbers);
		else
			bubble_sort_function(array_random_numbers);
	}
}

int main(void)
{
	int array_of_numbers[COUNT];

	printf("UNSORTED ARRAY\n");
	printf("Selection sort comparisons>    ");
	array_init(array_of_numbers, 0);

	printf("\tBubble sort comparisons>    ");
	array_init(array_of_numbers, 1);

	printf("SORTED ARRAY\n");
	printf("Selection sort comparisons>    ");
	array_init(array_of_numbers, 2);

	printf("\tBubble sort comparisons>    ");
	array_init(array_of_numbers, 3);

	return 0;
}

