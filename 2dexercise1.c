#include <stdio.h>
/** exercise 1 Write a function that searches for a 
	specific value along the diagonal of a square 2D array 
	(where the number of rows equals the number of columns). 
	If the element is found, return its position; otherwise, 
	return "Element not found on the diagonal." **/

void diagonalsearch (int rows, int cols, int a[rows][cols], int num){
	// linear search
	int found = 0;
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			if (r == c){
				if (num == a[r][c]){
				printf("The position is: [%d][%d]\n", r, c);
				found = 1;
				break;
				}
			}
		}
	}
	if (found == 0){
		printf("Element not found on the diagonal.\n");
	}
	
}

void print2d (int rows, int cols, int a[rows][cols]){
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			printf("  [%d][%d] = %d |", r, c, a[r][c]);
		}
		printf("\n");
	}
}

int main(){
	
	int rows = 3, cols = 3;
	int arr [3][3] = {
		{6, 4, 2},
		{5, 3, 1},
		{9, 7, 8}
	};
	
	print2d(rows, cols, arr);
	printf("\n");
	diagonalsearch(rows, cols, arr, 7);
	
	
	return 0;
}