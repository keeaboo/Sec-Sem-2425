#include <stdio.h>
// Fajardo, Ellimhykelle P. BSCS 1-4
// Structures Assignment 1 Problem 2
struct Seats {
		int num;
		char letter;
		char origletter; // the original letter if letter is marked X
	};
void printseats(int rows, int cols, struct Seats arr[rows][cols]);

int main (){
	
	int total = 20;
	int rows = 2; int cols = 4;
	int again = 1;
	struct Seats seat[5][4];
	
	// assign numbers and letters for the seats
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			seat[i][j].num = i+1;
			seat[i][j].letter = 65 + j;
			seat[i][j].origletter = 65 + j;
		}
	}

	// print seats
	printseats (rows, cols, seat);
	printf("\ninput format: number space letter (ex: 4 A)\n");
	// do while loop until all seats are marked X
	do {	
		// ask user to type in a seat num and letter
		printf("Please enter the number and letter of your seat: ");
		int seatnum = 0; char seatlet; //placeholders for user seat
		scanf("%d %c", &seatnum, &seatlet);
		//mark X for the letter of that seat
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				if (seatnum == seat[i][j].num){
					if (seatlet == seat[i][j].letter){
						seat[i][j].letter = 'X'; // mark X at the seat
					}
					else if (seatlet == seat[i][j].origletter && seat[i][j].letter == 'X'){ // for occupied seats
						printf("Sorry, the seat is already occupied, please choose another seat. \n");
						break;
					}
				}
			}
		}
		// print all seats again
		printseats (rows, cols, seat);
		
		printf("Would you like to choose another seat? 1 = Yes, 2 = No: ");
		scanf("%d", &again);
		if (again == 2){
			printf("Are you sure to exit? 0 = exit, 2 = cancel: ");
			scanf("%d", &again);
		}
	} while (again>0);
	
	
	return 0;
}

void printseats(int rows, int cols, struct Seats arr[rows][cols]){
	for (int i = 0; i < rows; i++){
		printf("%d\t", i+1);
		for (int j = 0; j < cols; j++){
			printf("%c\t", arr[i][j].letter);
		}
		printf("\n");
	}
}

// Problem 2
// Using the concept of structures, write a program to assign passenger seats in an airplane. 
//	1 A B C D
//	2 A B C D
//	3 A B C D
//	4 A B C D
//	5 A B C D
//The program should display the seat pattern, marking with an ‘X’ the seats already assigned.
//For example, after seats 1A, 2B, and 4C are taken, the display should look like:
//	1 X B C D
//	2 A X C D
//	3 A B C D
//	4 A B X D
//	5 A B C D
/* Seats are assigned by specifying a number and a letter. If the user types in a seat that is
already assigned, the program should say that the seat is occupied and ask for another choice.
The program should run until all seats are filled, or the user signals that the program should end. */