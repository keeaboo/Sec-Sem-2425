#include <stdio.h>

int main (){
	int numbers[2][3];
	int choice;
	int retry;
	int found = 0;

	printf("Enter 6 numbers for the array\n");
	for (int a = 0; a < 2; a++){
		for (int b = 0; b < 3; b++){
			printf("Enter a number for [%d][%d]: ", a, b);
			scanf("%d", &numbers[a][b]);
		}
	}
	
do {
	printf("What number are you searching for? ");
	scanf("%d", &choice);
	
	for (int a = 0; a < 2; a++){
		for (int b = 0; b < 3; b++){
			if (choice == numbers[a][b]){
				printf("The number is located in index [%d][%d]\n", a, b);
				found = 1;
				break;
			}
		}
	}
	
	if (found == 0){
		printf("The number is not found in the array.\n");
	}
	
	printf("Do you want to search again? (1)Yes, (2)No: ");
	scanf("%d", &retry);
	
} while (retry == 1);
	
	return 0;
}