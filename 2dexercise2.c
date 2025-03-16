#include <stdio.h>
/** Write a function that searches for the 
maximum value in a 2D array and returns 
its position (row and column) as well as the value itself. **/

void maxsearch (int rows, int cols, int a[rows][cols]){
	int max = [0 ][0];
	int rowposition = 0;
	int colposition = 0;
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			if (a[r][c] > max){
				max = a[r][c];
				rowposition = r;
				colposition = c;
			}
		}
	}
	printf("The maximum value is: %d, located at index [%d][%d]\n", max, rowposition, colposition);
	
}


int main(){
	int rows = 3, cols = 3;
	int arr [3][3] = {
		{6, 4, 2},
		{5, 3, 1},
		{9, 7, 8}
	};
	
	maxsearch(rows, cols, arr);
	
	
	return 0;
}