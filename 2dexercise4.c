#include <stdio.h>
/**Write a function that searches through a 2D array 
and returns a list of all even numbers. The function should 
return both the numbers and their corresponding row and column positions.**/

void findeven (int rows, int cols, int arr[rows][cols]){
	int found = 0;
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			if (arr[r][c]%2 == 0){
				printf("[%d][%d] = |%d|\n", r, c, arr[r][c]);
				found++;
			}
		}
	}
	if (found == 0){
		printf("No even numbers are found\n");
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

int main(){
	
	int rows = 3;
	int cols = 3;
	int arr [3][3] =
	{
		{9, 8, 7},
		{6, 5, 4},
		{3, 2, 1}
	};
	
	printf("ORGINAL ARRAY: \n");
	print2d(rows, cols, arr);
	
	printf("\nTHE EVEN NUMBERS ARE: \n");
	findeven(rows, cols, arr);
	
	return 0;
}