#include <stdio.h>

#define ROWS 3
#define COLS 3

void inputarray(int arr[ROWS][COLS]);
void printeven(int arr[ROWS][COLS]);
void print2d(int arr[ROWS][COLS]);

int main(){
	
	int choice;
	
	int arr [ROWS][COLS] = 
	{{4, 3, 1},
	{9, 0, 2},
	{10, 5, 6}};
	
	
	printf("Original array\n");
	print2d(arr);
	printeven(arr);
	
	return 0;
}

void inputarray(int arr[ROWS][COLS]){
	printf("\nEnter integers: \n");
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS; j++){
			printf("Enter [%d][%d]: ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
}

void printeven(int arr[ROWS][COLS]){
	int odd = 0;
	printf("\nThe even numbers are: \n");
	// search and print
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS; j++){
			// find even numbers
			if (arr[i][j]%2 == 0){
				// print the even numbers and their row and col position
				printf("arr[%d][%d] = %d \n", i, j, arr[i][j]);
				odd = 1;
			}
		}
	}
	if (odd == 0){
		printf("\nNo even numbers are present\n");
	}
}

void print2d(int arr[ROWS][COLS]){
	printf("\n");
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS; j++){
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}


//	do {
		//get rows and cols
//		printf("Enter the number of rows and cols: ");
//		scanf("%d %d", &rows, &cols);
//		
//		int array[rows][cols];
//		
//		inputarray(rows, cols, array);
		
//		printf("Do you want to try again? (1=yes, 2=no): ");
//		scanf("%d", &choice);
//		
//		if (choice == 2){
//			printf("Are you sure want to exit? (0=yes, 1=no)");
//			scanf("%d", &choice);
//		}
// 	}
// 	
// 	while (choice > 0);
	