#include <stdio.h>
//	original zero pointer
//  March 31, 2025

int main(){
	int *p;
	scanf("%d",p);
	p++;
	
	while(*p!=0){
		printf("Enter value\n");
		scanf("%d",p);
		p++;
	}
	--p;
	
	while(*p!=0){
		printf("%d\t",*p);
		--p;
	}
	
	return 0;
}