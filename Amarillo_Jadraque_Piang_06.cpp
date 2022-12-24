/*
* Names: Sanyiah Piang, Angel Jadraque, Kristine Amarillo
* This program outputs a console program to perform
* BFS and DFS graph traversals and search operations
*/

#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <stack>

using namespace std;

// Using template-type parameter so we can pass any data type as parameters
template<typename T>

// Creates a class 'Graph' using maps
class Graph {
	map<T, list<T> > list; //Create a map of lists of type 'T' called 'list'

public:
// Function that will add an edge from node a to node b
// For undirected graphs (bi-directional)
	void addEdge(T a, T b) {
		list[a].push_back(b);	//Adds node b to list a
		list[b].push_back(a);	//Adds node a to list b
	};

// Function for the DFS traversal
	void DFS(T srcNode) {

		cout << "\n";
		map<T, bool> visited;	//Creates a map for visited nodes
		stack<T> s;		//Creates a stack for the DFS values

		s.push(srcNode);		//Pushes the source node into the stack
		visited[srcNode] = true;	//Marks the source node as visited

		// While the stack is not empty,
		// pops the first element in the stack,
		// prints it out, takes the adjacent node of the
		// popped element, then pushes it again onto the stack
		while (!s.empty()) {

			T node = s.top();
			s.pop();

			cout << node << " ";

			for (T adjnode : list[node]) {
				if (!visited[adjnode]) {
					s.push(adjnode);
					//Mark the adjacent node as visited
					visited[adjnode] = true;
				}
			}
		} cout << "\n";
	}

// Function for the BFS traversal
	void BFS(T srcNode) {

		cout << "\n";
		map<T, bool> visited;	//Creates a map for visited nodes
		queue<T> q;		//Creates a queue for the BFS nodes

		q.push(srcNode);		//Pushes the source node to the queue
		visited[srcNode] = true;	//Marks the source node as visited
						//to avoid duplicates in the queue

		//While the queue is not yet empty,
		//this will remove the front node, print it,
		//then insert the adjacent nodes of the removed node
		//into the queue
		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << " ";

			for (T adjnode : list[node]) {
				if (!visited[adjnode]) {
					q.push(adjnode);
					//Mark the adjacent node as visited
					visited[adjnode] = true;
				}
			}
		} cout << "\n";
	}

// Function to search for a node using DFS
// It's basically the same as the DFS function
// but with added conditions for checking if item == node
	void searchDFS(T item, T srcNode) {

		map<T, bool> visited;	//Creates a map for visited nodes
		stack<T> s;		//Creates a stack for the DFS values

		s.push(srcNode);		//Pushes the source node into the stack
		visited[srcNode] = true;	//Marks the source node as visited

		// While the stack is not empty,
		// pops the first element in the stack,
		// prints it out, takes the adjacent node of the
		// popped element, then pushes it again onto the stack
		while (!s.empty()) {

			T node = s.top();
			s.pop();

			// Checks if the item is found in the graph,
			// then ends the while-loop
			if (node == item) {
				cout << "\nNode " << item << " is part of the graph." << endl;
				return;
			}

			for (T adjnode : list[node]) {
				if (!visited[adjnode]) {
					s.push(adjnode);
					//Mark the adjacent node as visited
					visited[adjnode] = true;
				}
			}
		}
		// If item is not found in the graph
		cout << "\nNode " << item << " is not part of the graph." << endl;
	}

// Function to search for a node using BFS
	void searchBFS(T item, T srcNode) {

		map<T, bool> visited;	//Creates a map for visited nodes
		queue<T> q;		//Creates a queue for the BFS nodes

		q.push(srcNode);		//Pushes the source node to the queue
		visited[srcNode] = true;	//Marks the source node as visited
						//to avoid duplicates in the queue

		// While the queue is not yet empty,
		// this loop will remove the front node, print it,
		// then insert the adjacent node of the removed node
		// into the queue
		while (!q.empty()) {

			T node = q.front();
			q.pop();

			// Checks if the item is found in the graph,
			// then ends the while-loop
			if (node == item) {
				cout << "\nNode " << item << " is part of the graph." << endl;
				return;
			}

			for (T adjnode : list[node]) {
				if (!visited[adjnode]) {
					q.push(adjnode);
					//Mark the adjacent node as visited
					visited[adjnode] = true;
				}
			}
		}
		// If item is not found in the graph
		cout << "\nNode " << item << " is not part of the graph." << endl;
	}
};

int main() {

	Graph<char> graph;
	int choice;

	do {
		cout << "\nGraph Traversal Program" << endl;
		cout << " [1] Perform DFS Traversal" << endl;
		cout << " [2] Perform BFS Traversal" << endl;
		cout << " [3] Search Item using DFS" << endl;
		cout << " [4] Search Item using BFS" << endl;
		cout << " [0] Exit" << endl;
		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice) {
		case 0:
			cout << "\nProgram has ended." << endl;
			break;
		case 1: {
			int g;
			cout << "\n[1] Graph 1" << endl;
			cout << "[2] Graph 2" << endl;
			cout << "\nSelect which graph to traverse: ";
			cin >> g;

			if (g == 1) {
				graph.addEdge('A', 'B');
				graph.addEdge('A', 'D');
				graph.addEdge('A', 'G');
				graph.addEdge('B', 'E');
				graph.addEdge('B', 'F');
				graph.addEdge('C', 'F');
				graph.addEdge('C', 'H');
				graph.addEdge('D', 'F');
				graph.addEdge('E', 'G');
				graph.DFS('A');
			}
			if (g == 2) {
				graph.addEdge('a', 'c');
				graph.addEdge('a', 'd');
				graph.addEdge('a', 'e');
				graph.addEdge('a', 'f');
				graph.addEdge('a', 'k');
				graph.addEdge('b', 'c');
				graph.addEdge('c', 'd');
				graph.addEdge('c', 'g');
				graph.addEdge('d', 'e');
				graph.addEdge('d', 'h');
				graph.addEdge('e', 'i');
				graph.addEdge('f', 'j');
				graph.addEdge('g', 'h');
				graph.addEdge('g', 'l');
				graph.addEdge('h', 'i');
				graph.addEdge('i', 'j');
				graph.addEdge('k', 'l');
				graph.DFS('a');
			}
		} break;
		case 2: {
			int g;
			cout << "\n[1] Graph 1" << endl;
			cout << "[2] Graph 2" << endl;
			cout << "\nSelect which graph to traverse: ";
			cin >> g;

			if (g == 1) {
				graph.addEdge('A', 'B');
				graph.addEdge('A', 'D');
				graph.addEdge('A', 'G');
				graph.addEdge('B', 'E');
				graph.addEdge('B', 'F');
				graph.addEdge('C', 'F');
				graph.addEdge('C', 'H');
				graph.addEdge('D', 'F');
				graph.addEdge('E', 'G');
				graph.BFS('A');
			}
			if (g == 2) {
				graph.addEdge('a', 'c');
				graph.addEdge('a', 'd');
				graph.addEdge('a', 'e');
				graph.addEdge('a', 'f');
				graph.addEdge('a', 'k');
				graph.addEdge('b', 'c');
				graph.addEdge('c', 'd');
				graph.addEdge('c', 'g');
				graph.addEdge('d', 'e');
				graph.addEdge('d', 'h');
				graph.addEdge('e', 'i');
				graph.addEdge('f', 'j');
				graph.addEdge('g', 'h');
				graph.addEdge('g', 'l');
				graph.addEdge('h', 'i');
				graph.addEdge('i', 'j');
				graph.addEdge('k', 'l');
				graph.BFS('a');
			}
		} break;
		case 3: {
			char item;
			int g;
			cout << "Enter node to search: ";
			cin >> item;
			cout << "\n[1] Graph 1" << endl;
			cout << "[2] Graph 2" << endl;
			cout << "Enter graph to search: ";
			cin >> g;

			if (g == 1) {
				graph.addEdge('A', 'B');
				graph.addEdge('A', 'D');
				graph.addEdge('A', 'G');
				graph.addEdge('B', 'E');
				graph.addEdge('B', 'F');
				graph.addEdge('C', 'F');
				graph.addEdge('C', 'H');
				graph.addEdge('D', 'F');
				graph.addEdge('E', 'G');
				graph.searchDFS(item, 'A');
			}
			if (g == 2) {
				graph.addEdge('a', 'c');
				graph.addEdge('a', 'd');
				graph.addEdge('a', 'e');
				graph.addEdge('a', 'f');
				graph.addEdge('a', 'k');
				graph.addEdge('b', 'c');
				graph.addEdge('c', 'd');
				graph.addEdge('c', 'g');
				graph.addEdge('d', 'e');
				graph.addEdge('d', 'h');
				graph.addEdge('e', 'i');
				graph.addEdge('f', 'j');
				graph.addEdge('g', 'h');
				graph.addEdge('g', 'l');
				graph.addEdge('h', 'i');
				graph.addEdge('i', 'j');
				graph.addEdge('k', 'l');
				graph.searchDFS(item, 'a');
			}
		} break;
		case 4: {
			char item;
			int g;
			cout << "Enter node to search: ";
			cin >> item;
			cout << "\n[1] Graph 1" << endl;
			cout << "[2] Graph 2" << endl;
			cout << "Enter graph to search: ";
			cin >> g;

			if (g == 1) {
				graph.addEdge('A', 'B');
				graph.addEdge('A', 'D');
				graph.addEdge('A', 'G');
				graph.addEdge('B', 'E');
				graph.addEdge('B', 'F');
				graph.addEdge('C', 'F');
				graph.addEdge('C', 'H');
				graph.addEdge('D', 'F');
				graph.addEdge('E', 'G');
				graph.searchBFS(item, 'A');
			}
			if (g == 2) {
				graph.addEdge('a', 'c');
				graph.addEdge('a', 'd');
				graph.addEdge('a', 'e');
				graph.addEdge('a', 'f');
				graph.addEdge('a', 'k');
				graph.addEdge('b', 'c');
				graph.addEdge('c', 'd');
				graph.addEdge('c', 'g');
				graph.addEdge('d', 'e');
				graph.addEdge('d', 'h');
				graph.addEdge('e', 'i');
				graph.addEdge('f', 'j');
				graph.addEdge('g', 'h');
				graph.addEdge('g', 'l');
				graph.addEdge('h', 'i');
				graph.addEdge('i', 'j');
				graph.addEdge('k', 'l');
				graph.searchBFS(item, 'a');
			}
		} break;
		default:
			cout << "\n Please choose a valid number!" << endl;
		}
	} while (choice != 0);

	return 0;
}
