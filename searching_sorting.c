#include <stdio.h>
#include <string.h>

// March 9, 2025
// Searching and Sorting of 1D and 2D arrays Practice

#define ROWS 2
#define COLS 5

void od_bubble(int array[], int size);
void od_insertion(int array[], int size);
void oneDi_Binary(int array[], int size, int search);
void oneDi_Linear(int array[], int size, int search);
void twoDi_Linear(int array[ROWS][COLS], int search);

int main(){
	int oneDi[10];
	int twoDi[2][5];
	int search = 0;
	int searchtype, sorttype;
	int algo;
	int searchagain, tryagain;
	//Let user choose if 1d or 2D
	int osize = 10;
	int arrtype;
	printf("What type of array do you want? (1)one-dimensional, (2)two-dimensional: ");
	scanf("%d", &arrtype);
	
	
	// 1D 1D 1D
	if (arrtype == 1){
			//Get values of 1D array from user
		do {
			for (int i=0; i<osize; i++){
				printf("Enter number for index [%d]: ", i);
				scanf("%d", &oneDi[i]);
			}
			
			// let user choose if sort or search
			printf("Enter the algorithm you want to execute (1)Searching, (2)Sorting: ");
			scanf("%d", &algo);
			
			if (algo == 1){
				do {
					//Let user choose if what search
					printf("Enter the type of search do you want to execute (1)Linear, (2)Binary: ");
					scanf("%d", &searchtype);
					
					printf("Enter the number you want to search: ");
					scanf("%d", &search);
					if (searchtype == 1){
						//1D Linear Search
						oneDi_Linear(oneDi, osize, search);
					}
					else if (searchtype == 1){
						//1D Binary Search
						// oneDi_Binary(oneDi, osize, search);
					}
					
					
					// Ask if the user wants to try again
					printf("Do you want to search again? (1)Yes, (2)No: ");
					scanf("%d", &searchagain);
					if (searchagain == 2){
						printf("Are you sure you want to exit? (0)Yes, (1)No: ");
						scanf("%d", &searchagain);
					}
				}
					while (searchagain > 0);
			}
			
			else if (algo == 2){
				printf("Proceed to sorting\n");
				//sorting
				printf("Enter the type of sort do you want to execute (1)Bubble, (2)Insertion, (3)Selection: ");
				scanf("%d", &sorttype);
				
				if (sorttype == 1){
					od_bubble(oneDi, osize);
				}
				else if (sorttype == 2){
					od_insertion(oneDi, osize);
				}
				else if (sorttype == 3){
					//od_selection(oneDi, osize);
				}
				
			}
				
			printf("Do you want to try again? (1)Yes, (2)No: ");
			scanf("%d", &tryagain);
			if (tryagain == 2){
				printf("Are you sure you want to exit? (0)Yes, (1)No: ");
				scanf("%d", &tryagain);
			}
		}
		while (tryagain > 0);
	}
	
	
	
	// 2D 2D 2D
	else if (arrtype == 2){
		//Get values of 2D array from user
		int rows = 2;
		int cols = 5;
		for (int row=0; row<rows ; row++){
			for (int col=0; col<cols; col++){
				printf("Enter number for index [%d][%d]: ", row, col);
				scanf("%d", &twoDi[row][col]);
			}
		}
		
		//Do-while for choosing 
		do {
			//Let user choose if what search
			printf("Enter the type of search do you want to execute (1)Linear, (2)Binary: ");
			scanf("%d", &searchtype);
			
			printf("Enter the number you want to search: ");
			scanf("%d", &search);
			if (searchtype == 1){
				//1D Linear Search
				twoDi_Linear(twoDi, search);
			}
			else if (searchtype == 1){
				//1D Binary Search
				// oneDi_Binary(oneDi, osize, search);
			}
			
			
			// Ask if the user wants to try again
			printf("Do you want to try again? (1)Yes, (2)No: ");
			scanf("%d", &searchagain);
			if (searchagain == 2){
				printf("Are you sure you want to exit? (0)Yes, (1)No: ");
				scanf("%d", &searchagain);
			}
		}
		while (searchagain > 0);
	}
	
	
	
	

	
//	2D Linear Search

	
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

void oneDi_Linear(int array[], int size, int search){
	int found = 0;
	for (int i=0; i<size; i++){
		if (array[i] == search){
			printf("The number you searched for is at index [%d]\n", i);
			found = 1;
			break;
		}
	}
	if (found == 0){
		printf("The number you searched for is not in the array\n");
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

/** void oneDi_Binary(int array[], int size, int search){
	int found = 0;
	int temp;
	//Sort the array first
	for (int i=0; i<size; i++){
		for (int j=0; j<size; j++){
			if (array[j+1]<array[i]){
				temp = array[i];
				array[i] = array[j+1];
				array[j+1] = temp;
			} 
		}
	}
	//print sorted array
	printf("Sorted array");
	for (int i=0; i<size; i++){
		printf("oneDi[%d] = %d\n", i, array[i]);
	}
	
	//binary search
		
	while (size > 1){
		//find the middle of the array
		int middle = size/2;
		if (search == middle){
			printf("The number you searched for is at index [%d]\n");
			found = 1;
			break;
		}
		else if (search > middle && search != middle){
			low = middle + 1;
			size = size - middle;
			middle = size/2;
		}
		else if (search < middle && search != middle){
			low = array[0];
			size = middle -1;
			middle = size/2;
		}
	}
}
**/