/*
* Names: Angel Jadraque, Sanyiah Piang, Kristine Amarillo
* This program outputs a console application using the stack ADT
* to perform operations for a basic kitchenware washing machine.
*/

#include <iostream>
using namespace std;

// Structure of the Node
struct Node
{
    string item;
    Node* link;
};

// top pointer to keep track of the top of the stack
Node* top = NULL;

// Function to check if stack is empty or not
bool EMPTY()
{
    if (top == NULL)
        return true; else
        return false;
}

// Function to check if stack is full or not
bool FULL()
{
    // Create new node ptr and allocate memory in heap
    Node* ptr = new Node();
    // Check if stack (heap) is full
    if (!ptr)
        return true; else
        return false;
}

// Function to insert an element in stack
void PUSH(string item)
{
    Node* ptr = new Node();
    if (FULL()) {
        cout << "The STACK is FULL. Cannot add kitchenware." << endl;
        exit(1);
    }
    ptr->item = item;
    ptr->link = top;
    top = ptr;
}

// Function to delete an element from the stack
void POP()
{
    if (EMPTY())
        cout << "The STACK is EMPTY. No more kitchenware to wash." << endl;
    else
    {
        Node* ptr = top;
        cout << top->item << " is being washed." << endl;
        top = top->link;
        delete(ptr);
    }
}

// Function to show the element at the top of the stack
void TOP()
{
    if (EMPTY())
        cout << "The STACK is EMPTY. No kitchenware to wash." << endl;
    else
        cout << top->item << " is next to be washed." << endl;
}

// Function to make the stack empty
void MAKENULL()
{
    if (EMPTY())
        cout << "The STACK is EMPTY. No kitchenware to wash." << endl;
    else
    {
        while (top != NULL)
        {
            cout << top->item << " is being washed." << endl;
            top = top->link;
        }
        cout << "All the kitchenware has been washed." << endl;
    }
}

// Main function
int main()
{

    int choice, flag = 1;
    string x;

    // Menu Driven Program using Switch
    while (flag == 1) {
        cout << "\nKitchenware Washing Machine\n \n [1] Add kitchenware\n [2] Wash kitchenware\n [3] Top kitchenware\n [4] Wash all\n [0] exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: cout << "Please enter a kitchenware to be washed(ex. Plate, Bowl, etc.): ";
            cin >> x;
            PUSH(x);
            break;
        case 2: POP();
            break;
        case 3: TOP();
            break;
        case 4: MAKENULL();
            break;
        case 0: cout << "The washing machine process has been terminated." << endl;
            flag = 0;
            break;
        default:cout << "Invalid Choice\n";
            break;
        }
    }

    return 0;
}