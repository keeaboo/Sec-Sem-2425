#include <stdio.h>
// File Handling, text file
// June 2, 2025

int main (){
	FILE *fp1;


	fp1 = fopen("C:\\Users\\Ellimhykelle Fajardo\\OneDrive\\Desktop\\hello.txt", "r"); 
	char name[80];
	
	while(fscanf(fp1, "%s", name) != EOF){
		printf("%s\n", name);		
	}
	
	fclose(fp1);


	
	
	
	
	
	return 0;
}










// evey file has its own file pointer
// .txt = text file, .dat = binary file

// OPENING A FILE fopen
// w mode = write means save or store or input data into the file, if the file exists file is erased, if not exisiting it is created
// r mode = read means retrieve or fetch or exract data from a file, if file exists marker is beginning, if nor exisitng error returned
// a mode = append, if the file exists the marker is positioned at end, if not existing it is created

// CLOSING A FILE fclose
// close the file previously opened for the data to be saved

// WRITING INTO FILE fprintf
// prints any type of value/varibale into the file.
// fprintf(file pointer, format specifier, source variable list);
// fprintf(fp, “%s\n”, name);

// RETRIEVE from a file fscanf
// fscanf(file pointer, format specifications, &estination variable list);
// fscanf(fp, "%s\n", name);
// fscanf(fp, "%d\n", &num);



//	while (ans == 1){
//		printf("Enter name:\t");
//		scanf("\n%s", name);
//		fprintf(fp1, "%s\n", name);
//		printf("Another name?\t");
//    	scanf("%d", &ans);
//	}

//	int age = 18;
//	int ans = 1;
	
//	filepointer = fopen("<filename>", "<mode>");

// READING
//	fp1 = fopen("C:\\Users\\Ellimhykelle Fajardo\\OneDrive\\Desktop\\hello.txt", "r"); 
//	fscanf(fp1, "%s", name);
//	printf("My name is %s", name);
//	fclose(fp1);

//	fp1 = fopen("C:\\Users\\Ellimhykelle Fajardo\\OneDrive\\Desktop\\hello.txt", "a"); 
//	fputc (code, fp1);
//	fclose(fp1);

//	fp1 = fopen("C:\\Users\\Ellimhykelle Fajardo\\OneDrive\\Desktop\\hello.txt", "r"); 
//	char name[80];
//	
//	while(fscanf(fp1, "%s\n", name) != EOF){
//		printf("%s\n", name);		
//	}
//	
//	fclose(fp1);

// use directory path

// remove(“lyn.txt”);
// rename(“bones.txt”, “basyong.txt”); filename to be renamed, new file name

// fseek
// beginning, end, current