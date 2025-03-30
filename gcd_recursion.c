#include <stdio.h>

// This code finds the GCD of two numbers and prints the result

// Recursion function
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main (){
	int x = 48;
	int y = 18;
	
	int result = gcd(x, y);
	
	printf("\nThe GCD of %d and %d is %d\n", x, y, result);
	
	return 0;
}



//    printf("a: %d, b: %d, a mod b: %d \n", a, b, a % b);