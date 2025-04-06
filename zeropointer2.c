#include <stdio.h>
// zero pointer
// April 7, 2025

int main (){
	int a = 0;
//	int *p = 7; gumagana naman to, bakit kapag scan hindi
//	int *p = &a;
	int *p = 0;
	printf("p = %x\n", p);
	printf("Enter a number for the pointer: "); // di na gumagana kahit tanggalin ko scanf kapag int *p; pero kapag int *p = &a; gumagana scanf
	scanf("%d", p);								// dahil walang pinopoint yung pointer kapag int *p; lang kaya di gumagana, yung address kasi na nasa p eh walang variable?
	printf("*p = %d\n", *p);
//	printf("a = %d\n", a);               


//  dapat ang bawat bagong value na ieenter, malalagay sa sunod sunod or magkakapitbahay na address through this loop, then ipiprint out sila pareverse through another loop
//	pero hindi ko magawa yung pag-assign ng next value sa kapitbahay na address

	while(*p<50){
		printf("\nstart p = %x\n", p);
		printf("Enter value\n");
		scanf("%d", p);
		printf("entered value a = %d\n", *p);
		++p; 	// maiincrement ang address na nakastore sa p, pero hindi mababago yung mismong address ng a
//		&a = p; 		you can't manipulate the address of a variable, but you can access to different addresses ig
		printf("origin a = %d\n", *(p-1));
		*p = 34;
		printf("*p = %d should be 34\n", *p);
	}

	printf("*p = %d\n", *p);
	

	return 0;
}