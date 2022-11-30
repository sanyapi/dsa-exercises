#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void clear() {
    system("cls");
}

void pause() {
    system("pause");
}

int countOccurenceRec(struct node *root, int item) {
    if(root == NULL) return 0;
    else if (root->key == item) {
        return countOccurenceRec(root->left, item) + 1 + countOccurenceRec(root->right, item);
    } else {
        return countOccurenceRec(root->left, item) + countOccurenceRec(root->right, item);
    }
}

int countOccurence(struct node *root, int item) {
    if(root == NULL) return -1;
    return countOccurenceRec(root, item);
}

void traverseInOrder(struct node *root) {
  if (root != NULL) {
    traverseInOrder(root->left);
    cout << root->key << "  ";
    traverseInOrder(root->right);
  }
}

void traversePreOrder(struct node *root) {
  if (root != NULL) {
    cout << root->key << "  ";
    traversePreOrder(root->left);
    traversePreOrder(root->right);
  }
}

void traversePostOrder(struct node *root) {
  if (root != NULL) {
    traversePreOrder(root->left);
    traversePreOrder(root->right);
    cout << root->key << "  ";
  }
}

struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

int findSuccessor(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current->key;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {
    clear();
    cout << "Tree is empty!" << endl;
    pause();
    clear();
    return root;
  }

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = minValueNode(root->right);

    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

bool search(struct node *root, int key) {
    if(root == NULL) return false;
    if(root->key == key) {
        return true;
    }
    bool searchLeft = search(root->left, key);
    if(searchLeft) return true;
    return search(root->right, key);
}

bool searchAndCount(struct node *root, int key, int count) {
    if(root == NULL) return false;
    if(root->key == key) {
        count++;
        cout << "A node with key " << key << " is found. Current count is " << count << endl;
        return true;
    }
    bool searchLeft = searchAndCount(root->left, key, count);
    if(searchLeft) return true;
    return searchAndCount(root->right, key, count);
}

bool searchIfMoreThanOne(struct node *root, int key, int count) {
    if(root == NULL) return false;

    if(count > 1) {
        return true;
    }

    if(root->key == key) {
        count ++;
        cout << "A node with key " << key << " is found. Current count is " << count << endl;
        return true;
    }
    bool searchLeft = searchIfMoreThanOne(root, key, count);
    if(searchLeft) return true;
    return searchIfMoreThanOne(root->right, key, count);

}

int findMaximum(struct node *root) {
    if(root == NULL) return INT_MIN;
    int max = root->key;
    int leftMax = findMaximum(root->left);
    int rightMax = findMaximum(root->right);
    if(leftMax > max) max = leftMax;
    if(rightMax > max) max = rightMax;
    return max;
}

int findMinimum(struct node *root) {
    if(root == NULL) return INT_MAX;
    int min = root->key;
    int leftMax = findMinimum(root->left);
    int rightMax = findMinimum(root->right);
    if(leftMax < min) min = leftMax;
    if(rightMax < min) min = rightMax;
    return min;
}

void findPredOrSuc(struct node *root, int item, struct node **x, struct node **y) {
    if(!root) {
        return;
    }

    findPredOrSuc(root->left, item, x, y);

    if(root && root->key > item) {
        if((!*y) || (*y) && (*y)->key > root->key) {
            *y = root;
        }
    } else if (root && root->key < item) {
        *x = root;
    }

    findPredOrSuc(root->right, item, x, y);

}

int main() {

    int exit = 0;
    int menuChoice;

    struct node *root = NULL;
    /**
    *   TEST DATA DO NOT UNCOMMENT
    */
    // root = insert(root, 50);
    // root = insert(root, 20);
    // root = insert(root, 60);
    // root = insert(root, 10);
    // root = insert(root, 30);
    // root = insert(root, 55);
    // root = insert(root, 70);
    // root = insert(root, 70);
    // root = insert(root, 70);
    // root = insert(root, 70);


    /**
    *   TEST DATA DO NOT UNCOMMENT
    */
    // root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);

    while(!exit) {
        clear();
        cout << "Binary Search Tree" << endl;
        cout << "[1] Insert Item" << endl;
        cout << "[2] Delete Item" << endl;
        cout << "[3] Search Item" << endl;
        cout << "[4] Find Maximun" << endl;
        cout << "[5] Find Minumum" << endl;
        cout << "[6] Find Successor" << endl;
        cout << "[7] Find Predecessor" << endl;
        cout << "[8] Display Tree" << endl;
        cout << "[0] Exit" << endl << endl;
        cout << "Enter choice: ";
        cin >> menuChoice;

        switch(menuChoice) {
            case 0: {
                clear();
                cout << "Program will exit." << endl;
                pause();
                clear();
                exit = 1;
            } break;
            case 1: {
                clear();
                int item;
                cout << "Enter item to insert: ";
                cin >> item;
                root = insert(root, item);
                clear();
                cout << "Item inserted to the tree." << endl;
                pause();
                clear();
            } break;
            case 2: {
                clear();
                if(!root) {
                    clear();
                    cout << "Tree is empty!\n";
                    pause();
                    clear();
                    break;
                }
                int item;
                cout << "Enter item to delete: ";
                cin >> item;
                clear();

                if(!search(root, item)) {
                    cout << "Item " << item << " is NOT in the tree." << endl;
                    pause();
                    clear();
                } else {
                    int count = countOccurence(root, item);
                    if(count > 1) {
                        clear();
                        cout << "Can not delete item as it has " << count << " occurrence in the tree." << endl;
                        pause();
                        clear();
                    } else {
                        clear();
                        root = deleteNode(root, item);
                        cout << "Item deleted successfully!" << endl;
                        pause();
                        clear();
                    }
                }
            } break;
            case 3: {
                clear();
                if(!root) {
                    clear();
                    cout << "Tree is empty!\n";
                    pause();
                    clear();
                    break;
                }
                int item;
                cout << "Enter item to search: ";
                cin >> item;
                clear();
                if(search(root, item)) {
                    cout << "Item " << item << " is FOUND in the tree." << endl;
                } else {
                    cout << "Item " << item << " is NOT in the tree." << endl;
                }
                pause();
                clear();
            } break;
            case 4: {
                clear();
                if(!root) {
                    clear();
                    cout << "Tree is empty!\n";
                    pause();
                    clear();
                    break;
                }
                cout << "\nMaximum item found is " << findMaximum(root) << "." << endl;
                pause();
                clear();} break;
            case 5: {
                clear();
                if(!root) {
                    clear();
                    cout << "Tree is empty!\n";
                    pause();
                    clear();
                    break;
                }
                cout << "\nMinimum item found is " << findMinimum(root) << "." << endl;
                pause();
                clear();
            } break;
            case 6: {
                clear();
                if(!root) {
                    clear();
                    cout << "Tree is empty!\n";
                    pause();
                    clear();
                    break;
                }
                int item;
                cout << "Enter an item to search for its successor: ";
                cin >> item;


                struct node *rootX = NULL, *rootY = NULL;
                if(!search(root, item)) {
                    clear();
                    cout << item << " does not exist in the tree." << endl;
                    pause();
                    clear();
                } else {
                    findPredOrSuc(root, item, &rootX, &rootY);

                    if(rootY) {
                        clear();
                        cout << "The successor of " << item << " is " << rootY->key << "." << endl;
                        pause();
                        clear();
                    } else {
                        clear();
                        cout << item << " has no successor.\n" << endl;
                        pause();
                        clear();
                    }
                }
            } break;
            case 7: {
                clear();
                if(!root) {
                    clear();
                    cout << "Tree is empty!\n";
                    pause();
                    clear();
                    break;
                }
                int item;
                cout << "Enter an item to search for its successor: ";
                cin >> item;


                struct node *rootX = NULL, *rootY = NULL;
                if(!search(root, item)) {
                    clear();
                    cout << item << " does not exist in the tree." << endl;
                    pause();
                    clear();
                } else {
                    findPredOrSuc(root, item, &rootX, &rootY);

                    if(rootX) {
                        clear();
                        cout << "The predecessor of " << item << " is " << rootX->key << "." << endl;
                        pause();
                        clear();
                    } else {
                        clear();
                        cout << item << " has no predecessor.\n" << endl;
                        pause();
                        clear();
                    }
                }
            } break;
            case 8: {
                clear();
                if(!root) {
                    clear();
                    cout << "Tree is empty!\n";
                    pause();
                    clear();
                    break;
                }
                cout << "Pre-order Traversal: ";
                traversePreOrder(root);
                cout << endl;

                cout << "In-order Traversal: ";
                traverseInOrder(root);
                cout << endl;

                cout << "Post-order Traversal: ";
                traversePostOrder(root);
                cout << endl;
                pause();
                clear();
            } break;
            default: {
                clear();
                cout << "Invalid choice!" << endl;
                pause();
                clear();
            }
        }
    }

    return 0;
}
