#include <stdio.h>
#include <stdlib.h>

// Fajardo, Ellimhykelle P. BSCS 1-4
// Structures Assignment 2

#define MAX_STOCKS 100
#define SIZE_COUNT 12 // Sizes 3 to 14

struct stock_no {
	int style_no; // 0 - 50
	int no_pairs[SIZE_COUNT]; // sizes 3 to 14
	float price;
	int isUsed;
};

int main() {
	struct stock_no inventory[MAX_STOCKS] = {0};
	int choice, index = 0;

	do {
		printf("\nWhat do you want to do?\n");
		printf("1 = Enter a new record\n");
		printf("2 = Display a record\n");
		printf("3 = Change the price of a stock item\n");
		printf("4 = Change the number on hand\n");
		printf("5 = Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1: {
				if (index >= MAX_STOCKS) {
					printf("Inventory full!\n");
					break;
				}
				printf("Enter style number (0-50): ");
				scanf("%d", &inventory[index].style_no);
				printf("Enter price: ");
				scanf("%f", &inventory[index].price);

				for (int i = 0; i < SIZE_COUNT; i++) {
					printf("Enter number of pairs for size %d: ", i + 3);
					scanf("%d", &inventory[index].no_pairs[i]);
				}
				inventory[index].isUsed = 1;
				printf("Record added with stock number %d.\n", index);
				index++;
				break;
			}
			case 2: {
				int stock_no;
				printf("Enter stock number to display: ");
				scanf("%d", &stock_no);

				if (stock_no >= 0 && stock_no < index && inventory[stock_no].isUsed) {
					printf("Stock Number: %d\n", stock_no);
					printf("Style Number: %d\n", inventory[stock_no].style_no);
					printf("Price: %.2f\n", inventory[stock_no].price);
					for (int i = 0; i < SIZE_COUNT; i++) {
						printf("Size %d: %d pairs\n", i + 3, inventory[stock_no].no_pairs[i]);
					}
				} else {
					printf("Invalid stock number.\n");
				}
				break;
			}
			case 3: {
				int stock_no;
				printf("Enter stock number to change price: ");
				scanf("%d", &stock_no);

				if (stock_no >= 0 && stock_no < index && inventory[stock_no].isUsed) {
					printf("Current price: %.2f\n", inventory[stock_no].price);
					printf("Enter new price: ");
					scanf("%f", &inventory[stock_no].price);
					printf("Price updated.\n");
				} else {
					printf("Invalid stock number.\n");
				}
				break;
			}
			case 4: {
				int stock_no, size, new_stock;
				printf("Enter stock number: ");
				scanf("%d", &stock_no);

				if (stock_no >= 0 && stock_no < index && inventory[stock_no].isUsed) {
					printf("Enter shoe size to update (3 to 14): ");
					scanf("%d", &size);

					if (size >= 3 && size <= 14) {
						printf("Enter new number of pairs: ");
						scanf("%d", &new_stock);
						inventory[stock_no].no_pairs[size - 3] = new_stock;
						printf("Stock updated.\n");
					} else {
						printf("Invalid size.\n");
					}
				} else {
					printf("Invalid stock number.\n");
				}
				break;
			}
			case 5:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice.\n");
		}
	} while (choice != 5);

	return 0;
}