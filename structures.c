#include <stdio.h>
#include <string.h>

// 04/28/25
// structs



int main(){
	struct Student {
	char name[80];
	int age;
	float grade;
	};
	struct Student student1; // create variable of type struct Student
	
	//assign values
	strcpy(student1.name, "Mhykee");
	student1.age = 18;
	student1.grade = 2.5;
	
	printf("Name: %s\n", student1.name);
	
	struct Student student[4];
	strcpy(student[0].name, "Nicole");
	student[0].age = 19;
	student[0].grade = 1.5;
	
	strcpy(student[1].name, "Aj");
	student[1].age = 20;
	student[1].grade = 3.5;
	
	strcpy(student[2].name, "Op");
	student[2].age = 40;
	student[2].grade = 1.0;
	
	// print struct student array elements and attributes
//	for (int i = 0; i < 4; i++){
//		printf("\nName: %s\n", student[i].name);
//		printf("Age: %i\n", student[i].age);
//		printf("Grade: %.2f\n", student[i].grade);
//	}
	
	// scan struct student array elements and attributes
//	for (int i = 0; i < 4; i++){
//		scanf("%[^\n]", student[i].name);
//		scanf("%i\n", &student[i].age);
//		scanf("%.2f\n", &student[i].grade);
//	}
//	fgets(student[0].name, sizeof(student[0].name), stdin);
//	student[0].name[strcspn(student[0].name, "\n")] = '\0';
////	scanf("%s", student[0].name);
//	scanf("%i\n", &student[0].age);
//	scanf("%.3f\n", &student[0].grade);
	
//	for (int i = 0; i < (4*3); i++){
//		fgets(student[i].name, sizeof(student[i].name), stdin);
//		student[i].name[strcspn(student[i].name, "\n")] = '\0';
//		scanf("%i\n", &student[i].age);
//		scanf("%.3f\n", &student[i].grade);
//	}
	
	
	for (int i = 0; i < 4; i++){
		printf("\nName: %s\n", student[i].name);
		printf("Age: %i\n", student[i].age);
		printf("Grade: %.2f\n", student[i].grade);
	}
	
	return 0;
}