/*
* Names: Sanyiah Piang, Angel Jadraque, Kristine Amarillo
* This program outputs a console program to perform operations
* on a list ADT implemented through linked lists.
*/

#include <iostream>

using namespace std;

// Structure of the node
struct Node {
	int item;
	struct Node *next; // read as, "Struct node pointer to 'next' node"
};

// Function declarations
int LISTLENGTH(struct Node* head);
void INSERT(int item, int position, struct Node** head);
void INSERTLAST(int item, struct Node** head);
void DELETE(int position, struct Node** head);
void DISPLAYLIST(struct Node* head);
void DELETELIST(struct Node** head);


// Function definitions

// Determines the length of the list
int LISTLENGTH(struct Node* head) {
	
	int len = 0;

	// Loop from head until NULL, incrementing len for each iteration
	while (head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

// Function to insert an item to the list
void INSERT(int item, int position, struct Node** head) {

	struct Node* newnode = new Node;
	newnode->item = item;
	newnode->next = NULL;

	int len = LISTLENGTH(*head);

	if (head == NULL) {		// Case 1: If the list is empty.
		*head = newnode;	// Set the new node as the head.
	}
	else if (position < 1 || position > len + 1) {
		cout << "\nInvalid position!" << endl;
		cout << "Can only place items at these positions: 1 to " << len + 1 << endl;
	}
	else if (position == 1) {	// Case 2: If the new node is at the start (position 1) of the list.
		newnode->next = *head;	// New node should point to the head node.
		*head = newnode;		// Set the new node as the head node.
	}
	else {									// Case 3: If inserting the new node anywhere in the list.
		int i = 1;
		struct Node* before = *head;		// Set the head node as the "before" node.
		while (i < position-1) {			// Until the condition is met, (1 < position - 1)
			before = before->next;			// set the before node to become the next node.
			i++;							// Increment the counter.
		}
		newnode->next = before->next;		// Set the new node to point to the node pointed to by the “before” node.
		before->next = newnode;				// Set the “before” node to point to the new node.
	}
}

// Function to insert an item at the end of the list
void INSERTLAST(int item, struct Node** head) {
	
	struct Node* newnode = new Node;
	newnode->item = item;
	newnode->next = NULL;

	if (*head == NULL) {
		*head = newnode;
	}
	else {
		struct Node* lastnode = *head;
		while (lastnode->next != NULL) {
			lastnode = lastnode->next;
		}
		lastnode->next  = newnode;
	}

}

// Function to delete items from the list
void DELETE(int item, struct Node** head) {
	int position = 1;

	if (*head == NULL) {
		cout << "\nThe list is empty!" << endl;
		return;
	}
	if ((*head)->item == item) {
		if ((*head)->item != NULL) {
			cout << "\nThe element " << (*head)->item << ", which is at position " << position << ", has been deleted." << endl;
			*head = (*head)->next;
			return;
		}
		else {
			*head = NULL;
			cout << "\nThe list is empty!" << endl;
			return;
		}
	}
	else if (((*head)->item != item) && (((*head)->next) == NULL)) { //when item is not at the start of the list and nothing comes next
	cout << "\nThe list contains no such element." << endl;
	return;
	}

	struct Node* current = *head;
	struct Node* prev = *head;

	while (current->next != NULL && current->item != item) { //traverses the list when the condition is met
		prev = current;
		current = current->next;
		position++;
	}
	if (current->item == item) {
		prev->next = prev->next->next;
		cout << "\nThe element " << current->item << ", which is at position " << position << ", has been deleted." << endl;
		free(current);
	}
	else {
		cout << "\nThe list contains no such element." << endl;
	}
}

// Function to display the items in the list
void DISPLAYLIST(struct Node* head) {

	struct Node* current = head;
	int i = 1;

	if (current != NULL) {
		while (current != NULL) {
			cout << "\nItem " << current->item << " is at position: " << i << endl;
			current = current->next;
			i++;
		}
	}
	else {
		cout << "\nThe list is empty!" << endl;
	}
}

// Function to delete the list
void DELETELIST(struct Node** head) {
	
	Node* current = *head;
	Node* next;
	
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;

	cout << "\nThe list has been emptied!" << endl;
}


// Main program
int main() {

	struct Node* head = NULL;
	int choice, item, n, position;

	do {
		cout << "\nList MENU\n" << endl;
		cout << "[1] Add Item" << endl;
		cout << "[2] Delete Item" << endl;
		cout << "[3] Display List" << endl;
		cout << "[4] Delete List" << endl;
		cout << "[0] Exit Program" << endl;
		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice) {
		case 1: cout << "\nPlease enter the item to be added: ";
				cin >> item;

				cout << "\nWhere to add the item?" << endl;
				cout << "[1] Start of the list" << endl;
				cout << "[2] End of the list" << endl;
				cout << "[3] Specific position" << endl;
				cout << "[0] Cancel" << endl;
				cout << "\nEnter choice: ";
				cin >> n;

				if (n == 1) {
					INSERT(item, 1, &head);
				}
				else if (n == 2) {
					INSERTLAST(item, &head);
				}
				else if (n == 3) {
					cout << "\nEnter a position: ";
					cin >> position;
					INSERT(item, position, &head);
				}
				break;
		case 2: cout << "\nEnter an item to be deleted: ";
				cin >> item;
				DELETE(item, &head);
				break;
		case 3: DISPLAYLIST(head);
				break;
		case 4: DELETELIST(&head);
				break;
		case 0: cout << "\nProgram terminated.";
				break;
		default: cout << "\nPlease choose a valid number!";
				break;
		}

	} while (choice != 0);

	return 0;
}