#include <stdio.h>

void print2darray(int rows, int cols, int matrix[rows][cols]){
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			printf("[%d][%d] = %d ", i, j, matrix[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int rows, cols, choice;
	
	//input dimensions
	printf("Enter the number of rows and cols: ");
	scanf("%d %d", &rows, &cols);
	// init array after 
	int matrix[rows][cols];
	
	//init matrix with zeros
	for (int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			matrix[i][j] = 0;
		}
	}
	
	printf("Matrix: \n");
	print2darray(rows, cols, matrix);
	
	do {
		int row, col, value;
		//input dimensions
		printf("Enter the number of row index (0-%d) and column index (0-%d) to input a value: ", rows-1, cols-1);
		scanf("%d %d", &row, &col);
		
		
		if (row >= 0 && row< rows && col >=0 && col<cols){
			printf("Enter value for matrix [%d][%d]: ", row, col);
			scanf("%d", &value);
			matrix[row][col] = value;
		}
		else {
			printf("Invalid row/column index, please try again\n");	
		}
		
		printf("\nUpdated Matrix\n");
		print2darray(rows, cols, matrix);
		
		// ask if the user wants to try again
		printf("Do you want to enter another value? (1=yes, 2=no): ");
		scanf("%d", &choice);
		
	}
	while (choice == 1);
	
	return 0;
}