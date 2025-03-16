#include <stdio.h>

// insertion sorting and binary searching from last monday

void print2d (int rows, int cols, int arr[rows][cols]){
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			printf("%d", arr[r][c]);
		}
		printf("\n");
	}
}

void insertion (int arr[], int size){
	for (int i = 0; i < size; i++){
		int key = arr[i];
		int j = i - 1;
		
		while(j >=0 && arr[j]> key){
			arr[j+1] = arr[j];
			j = j - 1;
		}
		
		arr[j+1] = key;
	}
}

void insertionwhole (int rows, int cols, int arr[rows][cols]){
	int size = rows*cols;
	int temp[size], index = 0;
	
	// convert 2d to 1d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			temp[index++] = arr[r][c];
		}
	}
	
	// sort
	insertion(temp, size);
	
	index = 0;
	// convert 1d to 2d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			 arr[r][c] = temp[index++];
		}
	}
	
	print2d(rows, cols, arr);
	
}

void ins_firstpass (int arr[], int size){

		int key = arr[1];
		int j = 0;
		
		while(j >=0 && arr[j]> key){
			arr[j+1] = arr[j];
			j = j - 1;
		}

		arr[j+1] = key;

}

void inswhole_firstpass (int rows, int cols, int arr[rows][cols]){
	int size = rows*cols;
	int temp[size], index = 0;
	
	// convert 2d to 1d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			temp[index++] = arr[r][c];
		}
	}
	
	// sort
	ins_firstpass(temp, rows);
	
	index = 0;
	// convert 1d to 2d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			 arr[r][c] = temp[index++];
		}
	}
	
	print2d(rows, cols, arr);
	
}


void binarysearch (int rows, int cols, int arr[rows][cols], int n){
	int l = 0; int r = (rows*cols) - 1;
	
	while (l<=r){
		int mid = l + (r - l)/2;
		
		int row = mid/cols;
		int col = mid%cols;
		
		if (n == arr[row][col]){
			printf("The number %d is located at [%d][%d]\n", arr[row][col], row, col);
			return;
		}
		else if (n > arr[row][col]){
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("The number doesn't exist in the array\n");
}

int main (){
	int rows = 2;
	int cols = 5;
	int num = 0;
	int arr [2][5] =
	{
		{8, 6, 4, 2, 7},
		{5, 3, 1, 9, 0}
	};

//	insertion(arr, 10);
//	print2d(rows, cols, arr);	
	printf("Original Array\n");
	print2d(rows, cols, arr);
	printf("\nINSERTION SORTED Array\n");
	insertionwhole(rows, cols, arr);
	
	printf("\n");
	
//	printf("After INSERTION sorting first pass\n");
//	inswhole_firstpass(rows, cols, arr);
	
	printf("\nPlease enter a number you want to search: ");
	scanf("%d", &num);
	
	binarysearch(rows, cols, arr, num);
	
	return 0;
}