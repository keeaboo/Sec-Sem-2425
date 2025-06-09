#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Fajardo, Ellimhykelle P. BSCS 1-4
// Structures Assignment 1
// Problem 3
/* The inventory of a shoe store lists shoes by stock number. With each stock number, there is
associated a style number in the range of 0 to 50, the number of pairs in each size (sizes range
from 3 to 14) and a price. A program is to be written to keep track of the inventory. The user is
given the following choices: enter a new record, display a record, change the price of the stock
item, or change the number on hand. When specifying a record the user may give either the
stock number, or the style number. The array index can be used as a stock number. If the user
decides to change the stock on hand, the program should ask which sizes will have their stock on
hand changed. The program should be designed to run indefinitely, keeping track of changed in
stock.*/

struct shoe_sizes {
	int no_pairs;
};

struct stock_no {  // array index = stock number
	int style_no; // 0 - 50
	struct shoe_sizes size; // sizes 3 - 14
	float price;
};

//struct shoe_inventory {
//	struct stock_no stock; 
//	
//};

int main (){
	int choice;
	// assign to pointer variable or array
	struct stock_no *shoe;
	shoe = (struct stock_no *)malloc(sizeof(struct stock_no));

	// do-while for asking the user what to do:
	// enter a new record, display a record, change the price of the stock item, or change the number on hand.
	printf("What do you want to do? \n1 = enter a new record \n2 = display a record \n3 = change the price of the stock item \n4 = change the number on hand.\n");
	scanf("%d", &choice);
	
	// enter a new record
	printf("Enter a new record:\n");
	
	return 0;
}