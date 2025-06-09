#include <stdio.h>
// Fajardo, Ellimhykelle P. BSCS 1-4
// Structures Assignment 1
// Problem 1
/* Write a program to score five – card poker hands into one of the following categories: 
nothing,one pair, two pairs, three of a kind, straight (in order), flush(all the same suit), full house(three
of a kind and one pair), four of a kind and a straight flush (both straight and flush). 
Use an array of structures to store the hand. 
The structure has one member for the value and one for the suit of the card.*/
struct Poker {
	int value;  // 11 = Jack, 12 = Queen, 13 = King,  14 = Ace
	char suit;
};	// S = Spade, C = Club/Clover, H = Heart, D = Diamond

int main (){
	struct Poker mycard[5];
	int valueCount[15] = {0};
	
	printf("Values:\t2-10 = spot cards, 11 = Jack, 12 = Queen, 13 = King, 14 = Ace\n");
	printf("Suits:\tS = Spade, C = Club/Clover, H = Heart, D = Diamond \n");
	// do-while for the program until user exits
	// user enters 5 cards
	printf("\nPlease enter your 5 poker cards in this format: value space suit (ex: 4 C for 4 of clubs)\n");
	for (int i = 0; i < 5; i++){
		int val; 
		char suit;
		printf("Enter Card %d:\t", i+1);
		scanf("%d %c", &val, &suit);
		
		mycard[i].value = val;
		mycard[i].suit = suit;
		
		// count occurences, or tally the value into another array
		// the value is the index
		valueCount[val]++;
	}
	
	// copy into new array
	int values[5];
	for (int i = 0; i < 5; i++) {
	    values[i] = mycard[i].value;
	}
	
	// bubble sort
	for (int i = 0; i < 4; i++) {
   		for (int j = i + 1; j < 5; j++) {
        	if (values[i] > values[j]) {
	            int temp = values[i];
	            values[i] = values[j];
	            values[j] = temp;
        	}
   		}
	}
	
	// check if straight
	int isStraight = 1;
	for (int i = 0; i < 4; i++) {
	    if (values[i] + 1 != values[i + 1]) {
	        isStraight = 0;
	        break;
	    }
	}
	
	// analyze for pairs
	int pairs = 0;
	int threekind = 0;
	int fourkind = 0;
    for (int i = 1; i <= 14; i++) {
        if (valueCount[i] == 2) {
            pairs++;
        }
        else if (valueCount[i] == 3) {
            threekind++;
        }
        else if (valueCount[i] == 4) {
            fourkind++;
        }
    }
    
	
	// Check for flush
    char firstSuit = mycard[0].suit;
    int sameSuitCount = 1;

    for (int i = 1; i < 5; i++) {
        if (mycard[i].suit == firstSuit) {
            sameSuitCount++;
        }
    }

    int isFlush = (sameSuitCount == 5);
    
    // output
    if (isStraight && isFlush) {
    	printf("Hand: Straight Flush\n");
	}
	else if (fourkind == 1) {
        printf("Hand: Four of a Kind\n");
    } 
    else if (threekind == 1 && pairs == 1){
    	printf("Hand: Full House!\n");
	}
    else if (isFlush) {
        printf("Hand: Flush\n");
	}
	else if (isStraight) {
    	printf("Hand: Straight\n");	
	}
	else if (threekind == 1) {
        printf("Hand: Three of a Kind\n");
    } 
    else if (pairs == 2) {
        printf("Hand: Two Pairs\n");
    } 
	if (pairs == 1) {
        printf("Hand: One Pair\n");
    } 
	else {
        printf("Hand: Nothing (no pair)\n");
    }
	
	return 0;
}


//	for (int i = 0; i < 5; i++){
//		int withpair = 0;
//		// one pair
//		struct Poker cardA = {mycard[i].value, mycard[i].suit}; // assign the value of a card from user to another struct var
//		printf("cardA = %d %c", cardA.value, cardA.suit);
//		
//		for (int j = 0; j < 5; j++){
//			if (cardA.value == mycard[j + 1].value){	
//				withpair += 1;
//			}	
//		}
//		
//		
//		printf("\n");
//	}