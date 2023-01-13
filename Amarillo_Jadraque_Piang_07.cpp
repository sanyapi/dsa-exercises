/*
* Names: Sanyiah Piang, Angel Jadraque, Kristine Amarilloto
* This program  outputs a console program to perform
* Sorting Algorithms to sort a sequence of numbers.
*/

#include<iostream>
#include <ctime>
#include <limits>

using namespace std;

void INPUT(int array[], int size) {
  for (int i = 0; i < size; i++)
    cin >> array[i];
}

void DISPLAY(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
}

// Selection sort
void SELECTION(int array[], int size) {
  int i, j, temp, small;
  for (i = 0; i < size - 1; i++) {
    small = i;
    for (j = i + 1; j < size; j++) //finding the smallest element
      if (array[j] < array[small])
        small = j;
    if (small != i) {
      temp = array[i]; //swapping
      array[i] = array[small];
      array[small] = temp;
    }
  }
}

// Merge sort
void merge(int array[], int l, int m, int r, int size) {
  int i = l;
  int j = m + 1;
  int k = l;

  // create temp array
  int temp[size];

  while (i <= m && j <= r) {
    if (array[i] <= array[j]) {
      temp[k] = array[i];
      i++;
      k++;
    } else {
      temp[k] = array[j];
      j++;
      k++;
    }
  }
  // copy the remaining elements of first half, if there are any
  while (i <= m) {
    temp[k] = array[i];
    i++;
    k++;
  }

  // copy the remaining elements of second half, if there are any
  while (j <= r) {
    temp[k] = array[j];
    j++;
    k++;
  }
  // copy the temp array to original array
  for (int p = l; p <= r; p++) {
    array[p] = temp[p];
  }
}
// l(left index) and r(right index) of the sub-array of arr to be sorted
void MERGE(int array[], int l, int r, int size) {
  if (l < r) {
    // find midpoint
    int m = (l + r) / 2;
    //recurcive mergesort firstand second halves
    MERGE(array, l, m, size);
    MERGE(array, m + 1, r, size);

    // merge
    merge(array, l, m, r, size);
  }
}

// Radix sort
int getmax(int array[], int size) {
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
    return max;
  }
}
// using counting sort to sort the elements in the basis of significant places
void countingsort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];

}
// main function to implement radix sort
void RADIX(int array[], int size) {
  // get maximum element
  int max = getmax(array, size);

  // apply counting sort to sort elements based on place value
  for (int place = 1; max / place > 0; place *= 10) {
    countingsort(array, size, place);
  }
}

int main() {
  int n, choice;
  int array[n];
  do {
    cout << "\nSorting Demonstration\n";
    cout << "\n [1] Input array\n";
    cout << " [2] Display array\n";
    cout << " [3] Perform SELECTION SORT\n";
    cout << " [4] Perform MERGE SORT\n";
    cout << " [5] Perform RADIX SORT\n";
    cout << " [0] Exit\n";
    cout << "\nEnter choice: ";
    while (!(cin >> choice) || choice < 0 || choice > 5) {
      cin.clear();
      cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
      cout << "Invalid choice. \n\nEnter choice: ";
    }
    cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
    time_t t1 = 0;
    time_t t2 = 0;
    switch (choice) {
    case 1:
      cout << "Enter the size of array: ";
      cin >> n;
      cout << "Enter " << n << " integers to be stored: ";
      INPUT(array, n);
      break;
    case 2:
      if (n == 0) {
        cout << "The array is empty." << endl;
        return main();
      } else
        cout << "The original input of array: ";
      DISPLAY(array, n);
      cout << " " << endl;
      break;
    case 3:
      if (n == 0) {
        cout << "The process cannot be done because the array is empty." << endl;
        return main();
      } else
        cout << "The original array: ";
      DISPLAY(array, n);
      cout << endl;
      cout << "Sorted array after selection: ";
      t1 = time(0);
      SELECTION(array, n);
      t2 = time(0);
      DISPLAY(array, n);
      cout << " " << endl;
      cout << "Time taken = " << t2 - t1 << " seconds\n";
      return main();
      break;
    case 4:
      if (n == 0) {
        cout << "The process cannot be done because the array is empty." << endl;
        return main();
      } else
        cout << "The original array: ";
      DISPLAY(array, n);
      cout << endl;
      cout << "Sorted array after merge: ";
      t1 = time(0);
      MERGE(array, 0, (n - 1), n);
      t2 = time(0);
      DISPLAY(array, n);
      cout << " " << endl;
      cout << "Time taken = " << t2 - t1 << " seconds\n";
      return main();
      break;
    case 5:
      if (n == 0) {
        cout << "The process cannot be done because the array is empty." << endl;
        return main();
      } else
        cout << "The original array: ";
      DISPLAY(array, n);
      cout << endl;
      cout << "Sorted array after radix: ";
      t1 = time(0);
      RADIX(array, n);
      t2 = time(0);
      DISPLAY(array, n);
      cout << " " << endl;
      cout << "Time taken = " << t2 - t1 << " seconds\n";
      return main();
      break;
    case 0:
      cout << "The program has ended." << endl;
      break;
    default:
      cout << "\nInvalid choice";
    }
  } while (choice != 0);
  return 0;
}
