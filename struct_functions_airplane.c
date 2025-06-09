#include <stdio.h>

// Define the structure
struct Seats {
    int num;
    char letter;
    char origletter;
};

// Function Prototypes
void assignSeats(int rows, int cols, struct Seats arr[rows][cols]);                               // Case 4: Array of structures
void printSeats(int rows, int cols, struct Seats arr[rows][cols]);                                // Case 4: Array of structures
void markSeat(int rows, int cols, struct Seats arr[rows][cols], int num, char let);               //  Case 1: Individual members
int isSeatTaken(struct Seats *seat, char letter);                                                 //  Case 3: Structure pointer
int isSeatAvailable(struct Seats s);                                                             //  Case 2: Whole structure
void displayPrompt();                                                                             

int main() {
    int rows = 2, cols = 4;
    int again = 1;
    struct Seats seat[5][4]; // ? 2D array of structures

    assignSeats(rows, cols, seat);      //  Case 4
    printSeats(rows, cols, seat);       //  Case 4
    displayPrompt();


	// Case 2: Check if a sample seat is available
    printf("\nSample seat availability:\n");
	if (isSeatAvailable(seat[0][0])) {
	    printf("Seat 1A is available.\n");
	} else {
	    printf("Seat 1A is already occupied.\n");
	}

    do {
        int seatNum;
        char seatLet;

        printf("\nPlease enter the number and letter of your seat: ");
        scanf("%d %c", &seatNum, &seatLet);

        // Check and mark seat
        int found = 0;
        for (int i = 0; i < rows && !found; i++) {
            for (int j = 0; j < cols && !found; j++) {
                if (seatNum == seat[i][j].num) {
                    if (!isSeatTaken(&seat[i][j], seatLet)) {        // ? Case 3
                        markSeat(rows, cols, seat, seatNum, seatLet); // ? Case 1
                        found = 1;
                    } else {
                        printf("Sorry, the seat is already occupied, please choose another seat.\n");
                        found = 1;
                    }
                }
            }
        }

        printSeats(rows, cols, seat); // ? Case 4

        printf("Would you like to choose another seat? 1 = Yes, 2 = No: ");
        scanf("%d", &again);
        if (again == 2) {
            printf("Are you sure to exit? 0 = exit, 2 = cancel: ");
            scanf("%d", &again);
        }
    } while (again > 0);

    return 0;
}

//  Case 4: Passing array of structures
void assignSeats(int rows, int cols, struct Seats arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j].num = i + 1;
            arr[i][j].letter = 65 + j;
            arr[i][j].origletter = 65 + j;
        }
    }
}
//  Case 1: Passing individual members
void markSeat(int rows, int cols, struct Seats arr[rows][cols], int num, char let) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j].num == num && arr[i][j].letter == let) {
                arr[i][j].letter = 'X';
                return;
            }
        }
    }
}

//  Case 2: Passing whole structure
int isSeatAvailable(struct Seats s) {
    return s.letter != 'X';  // returns 1 if available, 0 if occupied
}

//  Case 3: Passing structure pointer
int isSeatTaken(struct Seats *seat, char letter) {
    return seat->letter == 'X' && seat->origletter == letter;
}

//  Case 4: Passing array of structures
void printSeats(int rows, int cols, struct Seats arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < cols; j++) {
            printf("%c\t", arr[i][j].letter);
        }
        printf("\n");
    }
}

void displayPrompt() {
    printf("\nInput format: number space letter (ex: 1 A)\n");
}
