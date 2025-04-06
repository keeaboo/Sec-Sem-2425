#include <stdio.h>
// Dwarf or not Dwarf
// March 31, 2025

int main (){
	int arr[5] = {5, 3, 4, 2, 1};
	int *p = arr;
	int factors[5];
	
	printf("arr[5] = {");
	
	for (int i = 0; i < 5; i ++){
		printf("%d", arr[i]);
		
		if (i < 5 - 1){
			printf(", ");
		}
	}
	
	printf("}\n\n");
	
	for (int i = 0; i < 5; i++){
		int num = arr[i];
		int sum;
		
		// prints the element of the array
		printf("Input Number: %d\n", num);
		
		// prints the factors of that element
		printf("Factors are: ");
		for (int j = 1; j<=num; j++){
			if(num % j == 0){
				printf("%d ", j);
			}
		}
		printf("\n");
		
		// prints the + sign between the factors
		printf("Sum of the factors: ");
		for (int j = 1; j <= num; j++){
			if (num % j == 0){
				printf("%d", j);
				
				if (j != num){
					printf(" + ");
				}
				sum += j;
			}
		}
		// prints the sum at the end
		printf(" = %d", sum);
		
	
//		for (int i = 0; i < 5; i++){
//			factors[i] = 0;
//		}
		
		// the element is halved and prints it
		float half = (float)num/2;
		printf("\nHalf of the number %d / 2 = %.2f\n", num, half);
		
		// checks the dwarfity of the number
		if (sum > half){
			printf("%d is DWARF", num);
		}
		else {
			printf("%d is NOT DWARF", num);
		}
		
		// resets the sum to 0 for the next element/iteration
		sum = 0;
		printf("\n\n");
		
	}
	
	
	return 0;
}