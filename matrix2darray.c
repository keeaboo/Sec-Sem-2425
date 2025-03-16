#include <stdio.h>

// matrix transposition
void transpose(int rows, int cols, int matrix[rows][cols], int transposed[cols][rows]){
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			transposed[j][i] = matrix[i][j];
		}
	}
}

void print2darray(int rows, int cols, int matrix[rows][cols]){
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			printf("[%d][%d] = %d ", i, j, matrix[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int rows, cols;
	//get rows and cols
	printf("Enter the number of rows and cols: ");
	scanf("%d %d", &rows, &cols);
//	printf("Enter the number of cols: ");
//	scanf("%d", &cols);
	
	// initialize arrays after getting the rows and cols
	int arr[rows][cols];
	int transposed[cols][rows];
	//get values
	printf("Enter matrix elements: \n");
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++){
			printf("Enter [%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	
	printf("Original matrix\n");
	print2darray(rows, cols, arr);
	
	transpose(rows, cols, arr, transposed);
	
	printf("Transposed matrix\n");
	print2darray(cols, rows, transposed);
	
	return 0;
}