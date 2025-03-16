#include <stdio.h>

#define ROWS 2
#define COLS 5

void printarray(int array[], int size);
void print2darray(int array[ROWS][COLS]);

void od_bubble(int array[], int size);
void twodiBub_whole(int array[ROWS][COLS]);
void twodiBub_rows(int array[ROWS][COLS]);

void od_ins(int array[], int size);
void twodiIns_whole(int array[ROWS][COLS]);
void twodiIns_rows(int array[ROWS][COLS]);

void od_sel(int array[], int size);
void twodiSel_whole(int array[ROWS][COLS]);
void twodiSel_rows(int array[ROWS][COLS]);

int main(){
	
	int arr[ROWS][COLS] = 
	{{2, 1, 3, 7, 5},
	 {4, 7, 9, 8, 6}};
	int arro[10] = {2, 70, 32, 1, 45, 23, 67, 34, 25, 86};
	int arrosize = sizeof(arro[]) / sizeof(arro[0]);
	
	//twodiBub_whole(arr);
	//twodiBub_rows(arr);
	
//	twodiIns_whole(arr);
//	twodiIns_rows(arr);

//	od_ins(arro, 10);
//	printarray(arro, 10);

//	od_sel(arro, 10);
//	printarray(arro, 10);

//	twodiSel_whole(arr);
	twodiSel_rows(arr);
	
	return 0;
}

void od_bubble(int array[], int size){
	for (int i=0; i<size; i++){
		for (int j=0; j<(size-1); j++){
			if (array[j] > array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void printarray(int array[], int size){
	for (int i=0; i<size; i++){
		printf("[%d] = %d \n", i, array[i]);
	}
}

void print2darray(int array[ROWS][COLS]){
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS; j++){
			printf("[%d][%d] = %d ", i, j, array[i][j]);
		}
		printf("\n");
	}
}

void twodiBub_whole(int array[ROWS][COLS]){
	int size = ROWS * COLS;
	int temp[size], index = 0;
	//convert to 1D
	for (int a = 0; a<ROWS; a++){
		for (int b = 0; b<COLS; b++){
			temp[index++] = array[a][b];
		}
	}
	
	printf("After converting to 1d: \n");
	printarray(temp, size);
	od_bubble(temp, size);
	printf("After sorting the 1d: \n");
	printarray(temp, size);
	
	index = 0;
	//convert to 2D again
	for (int a = 0; a<ROWS; a++){
		for (int b = 0; b<COLS; b++){
			array[a][b] = temp[index++];
		}
	}
	printf("After converting to 2d: \n");
	print2darray(array);
}

void twodiBub_rows(int array[ROWS][COLS]){
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS-1; j++){
			for (int k=0; k<COLS-j-1; k++){
				if (array[i][k] > array[i][k+1]){
					int temp = array[i][k];
					array[i][k] = array[i][k+1];
					array[i][k+1] = temp;
				}
			}
		}
	}
	print2darray(array);
}

void od_ins(int array[], int size){
	for (int i=0; i<size; i++){
		int key = array[i];
		int j = i-1;
		
		while(j>=0 && array[j]>key){
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = key;
	}
}

void twodiIns_whole(int array[ROWS][COLS]){
	int size = ROWS * COLS;
	int temp[size], index = 0;
	
	//convert to 1D
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS; j++){
			temp[index++] = array[i][j];
		}
	}
	printf("After converting to 1d: \n");
	printarray(temp, size);
	od_ins(temp, size);
	printf("After sorting the 1d: \n");
	printarray(temp, size);
	
	//convert to 2D
	index = 0;
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS; j++){
			array[i][j] = temp[index++];
		}
	}
	
	printf("After converting to 2d: \n");
	print2darray(array);
}

void twodiIns_rows(int array[ROWS][COLS]){
	for (int i=0; i<ROWS; i++){
		for (int j=1; j<COLS; j++){
			int key = array[i][j];
			int k = j-1;
			
			while (k>=0 && array[i][k]>key){
				array[i][k+1] = array[i][k];
				k = k - 1;
			}
			array[i][k+1] = key;
		}
	}
	print2darray(array);
}

void od_sel(int array[], int size){
	for (int i=0; i<size-1; i++){
		int min_pos = i;
		for (int j=i+1; j<size; j++){
			if (array[j]<array[min_pos]){
				min_pos = j;
			}
		}
		if (min_pos != i){
			int temp = array[i];
			array[i] = array[min_pos];
			array[min_pos] = temp;
		}
	}
	
}

void twodiSel_whole(int array[ROWS][COLS]){
	int size = ROWS * COLS;
	int temp[size], index = 0;
	
	//convert to 1D
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS; j++){
			temp[index++] = array[i][j];
		}
	}
	
	printf("After converting to 1d: \n");
	printarray(temp, size);
	od_sel(temp, size);
	printf("After sorting the 1d: \n");
	printarray(temp, size);
	
	//convert to 2D
	index = 0;
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS; j++){
			array[i][j] = temp[index++];
		}
	}
	
	printf("After converting to 2d\n");
	print2darray(array);
	
}

void twodiSel_rows(int array[ROWS][COLS]){
	for (int i=0; i<ROWS; i++){
		for (int j= 0; j < COLS - 1; j++){
			int min_pos = j;
			for (int k = j+1; k<COLS; k++){
				if (array[i][k]<array[i][min_pos]) min_pos = k;
			}
			if (min_pos != j){
				int temp = array[i][j];
				array[i][j] = array[i][min_pos];
				array[i][min_pos] = temp;
			}
		}
	}
	print2darray(array);
}