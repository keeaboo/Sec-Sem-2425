#include <stdio.h>

/**Write a function that finds all elements 
in a 2D array where the number is divisible by 3. 
Return the numbers and their positions in the format: (value, row, column).**/

void divby3 (int rows, int cols, int arr[rows][cols]){
	int found = 0;
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			if (arr[r][c]%3 == 0 && arr[r][c] != 0){
				printf("[%d][%d] = |%d| \n", r, c, arr[r][c]);
				found ++;
			}
		}
	}
	printf("Total found numbers: %d\n", found);
	
	if (found == 0){
		printf("No numbers divisible by 3 are found.\n");
	}
	
}

void print2d (int rows, int cols, int arr[rows][cols]){
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			printf("[%d][%d] = |%d|\t", r, c, arr[r][c]);
		}
		printf("\n");
	}
}

int main() {
	
	int rows = 4; 
	int cols = 4;
	
	int arr[4][4] = 
	{
		{35, 31, 5},
		{0, 2, 8, 7},
		{1, -7, -7, -7},
		{46, 88, -7, -7}
	};
	
	printf("ORGINAL ARRAY: \n");
	print2d(rows, cols, arr);
	
	printf("\nNUMBERS DIVISIBLE BY 3: \n");
	divby3(rows, cols, arr);
	
	return 0;
}