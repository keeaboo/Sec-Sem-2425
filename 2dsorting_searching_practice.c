#include <stdio.h>

void print2d (int rows, int cols, int arr[rows][cols]){
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			printf("  [%d][%d] = | %d |", r, c, arr[r][c]);
		}
		printf("\n");
	}
}

void print1d (int arr[], int size){
	for (int i = 0; i < size; i++){
		printf(" [%d] = | %d | \n", i, arr[i]);
	}
}

void bubble (int arr[], int size){
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size - 1; j++){
			if (arr[j+1]<arr[j]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void bubble2d (int rows, int cols, int arr[rows][cols]){
	int size = rows*cols;
	int temp[size];
	int index = 0;
	
	//convert to 2d to 1d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			temp[index++] = arr [r][c];
		}
	}
	
	//sort the 1d
	bubble(temp, size);
	
	// set index to 0 agaiiinnn
	index = 0;
	
	//convert 1d to 2d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			arr [r][c] = temp[index++];
		}
	}
	
	print2d(rows, cols, arr);
	
}

void insertion (int arr[], int size){
	for (int i = 0; i < size; i++){
		int key =  arr[i];
		int j = i -1;
		
		while (j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		
		arr[j+1] = key;
	}
}

void insertion2d (int rows, int cols, int arr[rows][cols]){
	int size = rows*cols;
	int temp[size];
	int index = 0;
	
	//convert to 2d to 1d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			temp[index++] = arr [r][c];
		}
	}
	
	//sort the 1d
	insertion(temp, size);
	
	// set index to 0 agaiiinnn
	index = 0;
	
	//convert 1d to 2d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			arr [r][c] = temp[index++];
		}
	}
	
	print2d(rows, cols, arr);
	
}

void selection (int arr[], int size){
	for (int i = 0; i < size-1; i++){
		int min_pos = i;
		for (int j = i+1 ; j< size; j++){
			if(arr[j]<arr[min_pos]){
				min_pos = j;
			}
		}
		if (min_pos != i){
			int temp = arr[i];
			arr[i] = arr[min_pos];
			arr[min_pos] = temp;
		}
	}
}

void selection2d (int rows, int cols, int arr[rows][cols]){
	int size = rows*cols;
	int temp[size];
	int index = 0;
	
	//convert to 2d to 1d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			temp[index++] = arr [r][c];
		}
	}
	
	//sort the 1d
	selection(temp, size);
	
	// set index to 0 agaiiinnn
	index = 0;
	
	//convert 1d to 2d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			arr [r][c] = temp[index++];
		}
	}
	
	printf("\nSELECTION SORTED: \n");
	print2d(rows, cols, arr);
	
}

int binarysearch (int arr[], int n, int l, int r){
	int mid = l + (r - l)/2;
	
	if (l > r) return -1;
	

	if (n == arr[mid]){
		return mid;
	}
	else if (n > arr[mid]){
		l = mid + 1;
		return binarysearch(arr, n, l, r);
	}
	else if (n < arr[mid]){
		r = mid - 1;
		return binarysearch(arr, n, l, r);
	}
	
}

void binary2d (int rows, int cols, int arr[rows][cols], int n){
	int left = 0; int right = (rows*cols)-1;
	while (left <= right){
		int mid = left + (right - left)/2;
		
		int row = mid/cols; // Convert 1D index to 2D row index
		int col = mid%cols; // Convert 1D index to 2D col index
		
		if (arr[row][col] == n){
			printf("The number %d is located at index [%d][%d]", arr[row][col], row, col);
			return;
		} 
		else if (n > arr[row][col]){
			left = mid+1;
		}
		else if (n < arr[row][col]){
			right = mid-1;
		}
		
	}
	printf("Not found\n");
}

void convert2d_1d(int rows, int cols, int arr[rows][cols], int temp[]){

	int index = 0;
	
	//convert to 2d to 1d
	for (int r = 0; r < rows; r++){
		for (int c = 0; c < cols; c++){
			temp[index++] = arr [r][c];
		}
	}
	
}

int main(){
	int rows = 3;
	int cols = 3;
	int num = 0;
	int arr [3][3] = 
	{
		{8, 6, 4},
		{7, 5, 3},
		{9, 2, 1}
	};
	
	printf("original array: \n");
	print2d(rows, cols, arr);
	
	printf("\n");
	
//	printf("sorted 1d: \n");
//		bubble(arr, 9);
//	print1d(arr, 9);
//		insertion(arr, 9);
//	print1d(arr, 9);
//		selection(arr, 9);
//	print1d(arr, 9);

	printf("\n");

	printf("sorted 2d: \n");
//	bubble2d(rows, cols, arr);
//	insertion2d(rows, cols, arr);
	selection2d(rows, cols, arr);
	
	
	printf("\n\n");
	
//	convert 2d array to 1d before searching
//	int size = rows*cols;
//	int temp[size];
//	convert2d_1d(rows, cols, arr, temp);
//	print1d(temp, 9);
	
//	binary search 1d

	printf("\nPlease enter a number you want to search: ");
	scanf("%d", &num);
//	int left = 0; int right = (rows*cols)-1;
//	int result = binarysearch(temp, num, left, right);
//	if (result != -1){
//		printf("Index: %d\n", result);
//	}
//	else {
//		printf("Element not found\n");
//	}

//	binary search 2d
	binary2d(rows, cols, arr, num);
	
	
	
	return 0;
}