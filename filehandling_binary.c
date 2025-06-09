#include <stdio.h>
// File handling, binary file
// June 2, 2025

int main (){
	FILE *fp1;
	char name[80];


	fp1 = fopen("C:\\Users\\Ellimhykelle Fajardo\\OneDrive\\Desktop\\binary.dat", "r"); 
//	fwrite(&name, sizeof(name), 1, fp1);
	
	fread (&name, sizeof(name), 1, fp1);
	printf("%s", name);
	
	fclose(fp1);
	
	
	
	
	
	return 0;
}

// fwrite (fprintf in txt)
// fwrite(&source variable, size of source variable in bytes, 
// no. of data items to be appended, file pointer);
// fwrite(&name, sizeof(name),1,fp);
// fwrite(&name, sizeof(name), 1, fp1);

// fread (&name, sizeof(name), 1, fp);