#include <stdio.h>
// zero pointer
// April 6, 2025

int main (){
	int a = 0;
	int *p = &a; 
	printf("Enter a number for the pointer: ");
	scanf("%d", p);
	printf("*p = %d\n", *p);
	printf("a = %d\n", a);               
//	
	
	while(*p!=0){
		printf("\nstart p = %x\n", p);
		printf("Enter value\n");
		scanf("%d", p);
		printf("entered value a = %d\n", *p);
		++p; // increment the address of a? i think it should be p's address
		printf("cremented p or address of a = %x (by p)\n", p); // iba yung address na nakastore sa p kaysa sa address ng a after incrementing
		printf("address of a = %x (by &a)\n", &a); // baka dahil pointers don't directly manipulate the address of a, just its value
		printf("value at incremented p? %d or %x\n", *p, *p); // yung value na nakastore sa address na nakastore sa p ay yung same incremented address din?
		printf("origin a = %d\n", *(p-1));
		*p = 34;
		printf("*p = %d should be 34\n", *p);
	}
	--*p;
	printf("*p = %d\n", *p);
	
	while(*p!=0){
		printf("numbers entered %d\n",*p);
		--*p;
	}
	
	return 0;
}