#include <bits/stdc++.h>
#include <string.h>
#include <limits>

using namespace std;

// Structure of Node.
struct Node {
  char name[80];
  char order[80];
  Node * link;
};

struct INIT {
  Node * front, * rear;

  INIT() {
    front = rear = NULL;
  }

  //Function to check if queue is empty or not
  bool EMPTY() {
    if (front == NULL && rear == NULL)
      return true;
    else
      return false;
  }

  //function to show the element at front
  void FRONT() {
    if (EMPTY())
      cout << "The QUEUE is EMPTY. No order to serve." << endl;
    else
      cout << "Next order: " << front -> order << " of customer " << front -> name << "." << endl;
  }

  //function to enter elements in queue
  void ENQUEUE(char name[], char order[]) {
    Node * ptr = new Node(); {
      strcpy(ptr -> name, name);
      strcpy(ptr -> order, order);
      ptr -> link = NULL;
      //If inserting the first element/node
      if (front == NULL) {
        front = ptr;
        rear = ptr;
      } else {
        rear -> link = ptr;
        rear = ptr;
      }
    }
  }

  //function to delete/remove element from queue
  void DEQUEUE() {
    Node * ptr = front;
    if (EMPTY()) {
      cout << "The QUEUE is EMPTY. No order to serve." << endl;
    } else if (front == rear) {
      cout << "Now serving " << front -> order << " to customer " << front -> name << "." << endl;
      free(front);
      front = rear = NULL;
    } else {
      cout << "Now serving " << front -> order << " to customer " << front -> name << "." << endl;
      front = front -> link;
      free(ptr);
    }
  }

};

//Main Function
int main() {
  INIT i;
  int choice;
  do {
    cout << "\nAJP Coffee Shop Menu:\n";
    cout << "\n [1] Fall in line\n";
    cout << " [2] Serve order\n";
    cout << " [3] Next order\n";
    cout << " [4] Closing time\n";
    cout << " [0] Exit\n";
    cout << "\nEnter choice: ";
    while (!(cin >> choice) || choice < 0 || choice > 5) {
      cin.clear();
      cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
      cout << "Invalid choice. \n\nEnter choice: ";
    }
    cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');

    switch (choice) {
    case 1:
      Node n;
      cout << "Enter the name of person falling in line: ";
      cin.getline(n.name, 80);
      cout << "Enter the order: ";
      cin.getline(n.order, 80);
      i.ENQUEUE(n.name, n.order);
      break;
    case 2:
      i.DEQUEUE();
      break;
    case 3:
      i.FRONT();
      break;
    case 4:
      if (i.EMPTY()) {
        cout << "The QUEUE is EMPTY. No order to serve." << endl;
      } else {
        while (!i.EMPTY()) {
          i.DEQUEUE();
        }
        cout << "All the orders have been served." << endl;
      }
      break;
    case 0:
      cout << "The order system has been terminated." << endl;
      break;
    }
  } while (choice != 0);

  return 0;
}
