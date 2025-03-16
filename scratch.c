#include <stdio.h>

#define ROWS 2
#define COLS 5

void od_bubble(int array[], int size);
void od_insertion(int array[], int size);
void twoDi_Linear(int array[ROWS][COLS], int search);

int main(){
	
	int arr[ROWS][COLS] = 
	{{2, 1, 3, 7, 5},
	 {4, 7, 9, 8, 6}};
	int arro[10] = {2, 70, 32, 1, 45, 23, 67, 34, 25, 86};
	
	twoDi_Linear(arr, 4);
	//od_bubble(arro, 10);
	od_insertion(arro, 10);
	
	return 0;
}

void od_bubble(int array[], int size){
	for (int i=0; i<size; i++){
		for (int j=0; j<(size - 1); j++){
			if (array[j] > array[j+1]){
				//swap
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	printf("Sorted array:\n");
	for (int i=0; i<size; i++){
		printf("oneDi[%d] = %d\n", i, array[i]);
	}
}

void od_insertion(int array[], int size){
	for (int i=0; i<size; i++){
		int key = array[i];
		int j = i - 1;
		
		while (j >= 0 && array[j] > key){
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
	printf("Sorted array:\n");
	for (int i=0; i<size; i++){
		printf("oneDi[%d] = %d\n", i, array[i]);
	}
}

void twoDi_Linear(int array[ROWS][COLS], int search){
	int found = 0;
	for (int a = 0; a < ROWS; a++){
		for (int b = 0; b < COLS; b++){
			printf("row: %d, col: %d\n", a, b);
			if (search == array[a][b]){
				printf("The number you searched for is at index [%d][%d]\n", a, b);
				found = 1;
				break;
			}
		}			
	}
	if (found == 0){
		printf("The number you searched for is not in the array\n");
	}	
}