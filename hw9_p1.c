/*	Author: Parker Mathewson						*
 *	Date: 4/8/12								*
 *	Comments: This program is one that takes a grid of gas station prices	*
 *			and compares them to eachother in accordance to your	*
 *			position on the grid. The program will then calculate	*
 *			where to go to get the cheapest gas fillup.		*/

#include<stdio.h>
#include<math.h>
#define ROW 10
#define COL 10

float price_function(float gas_price_grid[][COL], int position_x, int position_y, int *gas_position_x, int *gas_position_y, 
float *distance)
{
	int row_counter=0, col_counter=0;
	float distance_temp=0, price=100;

	for(row_counter=0; row_counter<ROW; row_counter++)
	{
		for(col_counter=0; col_counter<COL; col_counter++)
		{
			distance_temp = ((pow(.5*(position_x-col_counter), 2)))+((pow(.5*(position_y-row_counter), 2)));
			distance_temp = sqrt(distance_temp);
			if(price>(10*(gas_price_grid[row_counter][col_counter])+(gas_price_grid[row_counter][col_counter]*(distance_temp/50))))
			{
				price = (10*(gas_price_grid[row_counter][col_counter]) + gas_price_grid[row_counter][col_counter]*(distance_temp/50));
				*distance = distance_temp;
				*gas_position_x = row_counter;
				*gas_position_y = col_counter;
			}
		}
	}
	return price;
}

int main(void)
{
	float gas_price_grid[ROW][COL], *distance, price_to_fill, distance_nonptr;
	int row_counter=0, col_counter=0, position_x=0, position_y=0, gas_position_nonptr=0, gas_position_y_nonptr=0;
	int *gas_position_x, *gas_position_y;

	gas_position_x=&gas_position_nonptr;
	gas_position_y=&gas_position_y_nonptr;
	distance=&distance_nonptr;

	FILE *input_file;
	input_file = fopen("prices.dat", "r");
	if(input_file == NULL) printf("There was an error reading the file.");
	else
	{
		for(row_counter=0; row_counter<ROW; row_counter++)
			for(col_counter=0; col_counter<COL; col_counter++)
				fscanf(input_file, "%f", &gas_price_grid[row_counter][col_counter]);

		printf("Please enter your current x location in the grid: ");
		scanf("%d", &position_x);
		fflush(stdin);
		printf("Please enter your current y location on the grid: ");
		scanf("%d", &position_y);

		price_to_fill = price_function(gas_price_grid, position_x, position_y, gas_position_x, 
						gas_position_y, distance);

		printf("The minimum total cost to fill up is $%.2f at location row %d and column %d.\n", price_to_fill, 
			*gas_position_x, *gas_position_y);

		printf("The gas station has a gas price of (%.2f) and is %.2f miles away from your\n", 
			gas_price_grid[gas_position_nonptr][gas_position_y_nonptr], *distance);

		printf("current location at row %d and column %d.\n", position_x, position_y);
	}

	return(0);
}

