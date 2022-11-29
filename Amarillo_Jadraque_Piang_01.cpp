/*
* Names: Sanyiah Piang, Angel Jadraque, Kristine Amarillo
* This program outputs a console program to perform operations
* on a list ADT implemented using an array.
*/

#include <iostream>
#define MAXSIZE 10 //maximum capacity of the array.

using namespace std;

struct list {
	int items[MAXSIZE];
	int length;	//using 'length' instead of 'end' for readability
};

//Function declaration
void INSERT(int item, int position, list& theList);
void DELETEITEM(int item, list& theList);
void DISPLAY(list& theList);
void DELETELIST(list& theList);

//Main program
int main() {

	int choice, item, n, position;
	list myList{};
	myList.length = -1; //shows that the list is empty.

	do{
		cout << "\nList MENU\n" << endl;
		cout << "[1] Add Item" << endl;
		cout << "[2] Delete Item" << endl;
		cout << "[3] Display List" << endl;
		cout << "[4] Delete List" << endl;
		cout << "[0] Exit Program" << endl;
		cout << "\nEnter choice: ";
		cin >> choice;

		switch(choice) {
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
						INSERT(item, 0, myList);
					}
					else if (n == 2) {
						INSERT(item, myList.length + 1, myList);
					}
					else if (n == 3) {
						cout << "\nEnter a position: ";
						cin >> position;
						INSERT(item, position, myList);
					}
					break;
			case 2: cout << "\nEnter an item to be deleted: ";
					cin >> item;
					DELETEITEM(item, myList);
					break;
			case 3: DISPLAY(myList);
					break;
			case 4: DELETELIST(myList);
					break;
			case 0: cout << "\nProgram terminated." << endl;
					break;
			default: cout << "\nPlease choose a valid number!" << endl;
		}
	} while (choice != 0);

	return 0;
}

//Function definitions

//Function to insert an item to the list
void INSERT(int item, int position, list& theList)
{
	if (theList.length >= MAXSIZE-1) //subtracting 1 to MAXSIZE to prevent buffer overrun
	{
		cout << "\nYour list is FULL." << endl;
	}
	else if (position > theList.length+1 || position < 0)
	{
		cout << "\nInvalid position!" << endl;
	}
	else
	{
		for (int i = theList.length; i >= position; i--)
		{
			theList.items[i + 1] = theList.items[i];
		}
		theList.length += 1;
		theList.items[position] = item;
	}
}

//Function to delete an item from the list
void DELETEITEM(int item, list& theList)
{
	if (theList.length < 0)
	{
		cout << "\nThe list is empty!" << endl;
	}
	else if (theList.length >= 0)
	{
		for (int i = 0; i <= theList.length; i++) // 'i' refers to position (index) of the item and its value
		{
			if (item == theList.items[i])
			{
				theList.length -= 1;
				theList.items[i] = theList.items[i + 1];
				cout << "\nThe element " << item << ", which is at position " << i << ", has been deleted." << endl;
			}
			else
			{
				cout << "\nThe list contains no such element." << endl;
			}
		}
	}
}

//Function to display all items and their respective positions in the list
void DISPLAY(list& theList)
{
	if (theList.length == -1)
	{
		cout << "\nThe list is empty." << endl;
	}
	else
	{
		for (int i = 0; i <= theList.length; i++)
		{
			cout << "\nItem " << theList.items[i] << " is at position " << "[" << i << "]" << endl;
		}
	}
}

//Function to delete all items in the list
void DELETELIST(list& theList)
{
	int i = 0;

	while (theList.length != -1)
	{
		for (i = 0; i <= theList.length; i++)
		theList.length -= 1;
		theList.items[i] = theList.items[i + 1];
	}
	cout << "\nThe list has been emptied!" << endl;
}