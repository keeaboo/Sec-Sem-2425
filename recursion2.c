#include <stdio.h>
// function recursion from LEC

void fun(int x, int y)
{
	if (x > 40)
		return;
	x += y;
	fun(x, y);
	
	printf("x: %d\n", x);;
}

int main(){
	int x = 10;
	fun (10, 10);
	printf("main x: %d\n", x);
	
	return 0;
}