#include <malloc.h>
#include <stdio.h>
// May 26, 2025 Lecture
// Linked List

struct node {
	char value;
	struct node *nextnodeaddress;
};

int main (){
	int choice;
	struct node *current, *head, *tail, *temp, *newnode;
	current = NULL;
	head = NULL;
	tail = NULL;
	
	printf("Linked List\n");
	
	current = (struct node*) malloc(sizeof(struct node));
	current->value = 'A';
	current->nextnodeaddress = NULL;
	head = current;
	tail = current;
	printf("current value = %c\n", current->value);
	printf("head = %c\n", head->value);
	printf("tail = %c\n", tail->value);
	
	current = (struct node*) malloc(sizeof(struct node));
	current->value = 'B';
	current->nextnodeaddress = NULL;
	tail->nextnodeaddress = current;
	tail = current;
	printf("current value = %c\n", current->value);
	printf("head = %c\n", head->value);
	printf("tail = %c\n", tail->value);
	
	current = (struct node*) malloc(sizeof(struct node));
	current->value = 'C';
	current->nextnodeaddress = NULL;
	tail->nextnodeaddress = current;
	tail = current;
	printf("current value = %c\n", current->value);
	printf("head = %c\n", head->value);
	printf("tail = %c\n", tail->value);
		
	do {
		printf("\nWhat do you want to do?\n");
		printf("1 = Insert at beginning\n");
		printf("2 = Insert at end\n");
		printf("3 = Insert after an element\n");
		printf("4 = Delete the beginnning\n");
		printf("4 = Delete the end\n");
		printf("5 = Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: {
				// insertion at beginning
				printf("\nInsertion at the beginning: \n");
				current = (struct node*)malloc(sizeof(struct node));
				printf("Enter data you want to insert: ");
				scanf("%c", &current->value);
				current->nextnodeaddress = head;
				head = current;
				
				printf("current value = %c\n", current->value);
				printf("head = %c\n", head->value);
				printf("tail = %c\n", tail->value);
				break;
			}
			case 2: {
				// insertion at end
				
				// make the next pointer of the last node point to the new node
				current = (struct node* ) malloc (sizeof(struct node)); 
				current->nextnodeaddress  = NULL;
				head->nextnodeaddress = current;
				tail = current;	
				
				printf("\nInsertion at the end: \n");
				current = (struct node*)malloc(sizeof(struct node));
				printf("Enter data you want to insert: ");
				scanf("%c", &current->value);
				current->nextnodeaddress = 0;
				temp = head;
				while (temp -> nextnodeaddress!=0)
				{	
					temp =  temp->nextnodeaddress;
				}
				temp->nextnodeaddress = current;
				tail = current;	
				
				printf("current value = %c\n", current->value);
				printf("head = %c\n", head->value);
				printf("tail = %c\n", tail->value);
						break;
			}
		}
		
	
	
	
		// iserting after an element
	//	int pos, count;
	//	newnode = (struct node*)malloc(sizeof(struct node));
	//	printf("Enter the position you want");
	//	scanf("%d",&pos);
	//	if(pos > count)
	//		printf("Position is invalid");
	//	else {	
	//		temp = head;
	//		while(i < pos)
	//		{	temp = temp->nextnodeaddress;
	//			i++;
	//		}
	//	}
	//	printf("Enter data you want to insert");
	//	scanf("%d", &newnode->value);
	//	newnode->nextnodeaddress = temp->value;
	//	temp->nextnodeaddress = newnode;
	
		
		// delete the first node
		
		// delete the last node
		
		
		
	}while (choice != 5);
	
	
	return 0;
	
}