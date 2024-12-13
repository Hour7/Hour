#include <iostream>
using namespace std;

void showelement(int arr[], int size) {
      for (int i = 0; i < size; i++) {
            cout << "Array " << i << " : " << arr[i] << endl;
      }
}

void insert(int arr[], int &size, int position, int value) {
      if (position < 0 || position > size || size >= 20) {
            cout << "Invalid position or array is full!" << endl;
            return;
      }
      for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
      }
      arr[position] = value;
      size++;
}

void deleteByPosition(int arr[], int &size, int position) {
      if (position < 0 || position >= size) {
            cout << "Invalid position!" << endl;
            return;
      }
      for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
      }
      size--;
}

void deleteByValue(int arr[], int &size, int value) {
      int i = 0;
      while (i < size) {
            if (arr[i] == value) {
                  for (int j = i; j < size - 1; j++) {
                  arr[j] = arr[j + 1];
                  }
                  size--;
            } else {
                  i++;
            }
      }
}

int main() {
      int arr[20];
      int size;
      cout << "Enter the size of the array (max 10): ";
      cin >> size;

      if (size > 20 || size <= 0) {
            cout << "Invalid size! Exiting program." << endl;
            return 0;
      }

      cout << "Enter " << size << " elements for the array:" << endl;
      for (int i = 0; i < size; i++) {
            cout << "Element " << i << ": ";
            cin >> arr[i];
      }

      int op;
      do {
            cout << "\nChoose an option:\n";
            cout << "1. Show elements\n";
            cout << "2. Insert an element\n";
            cout << "3. Delete an element by position\n";
            cout << "4. Delete all elements by value\n";
            cout << "5. Exit\n";
            cout << "Your choice: ";
            cin >> op;

            switch (op) {
                  case 1:
                        showelement(arr, size);
                  break;
                  case 2: {
                        int pos, value;
                        cout << "Enter position (0 to " << size << "): ";
                        cin >> pos;
                        cout << "Enter value to insert: ";
                        cin >> value;
                        insert(arr, size, pos, value);
                  break;
                  }
                  case 3: {
                        int pos;
                        cout << "Enter position (0 to " << size - 1 << "): ";
                        cin >> pos;
                        deleteByPosition(arr, size, pos);
                  break;
                  }
                  case 4: {
                        int value;
                        cout << "Enter value to delete: ";
                        cin >> value;
                        deleteByValue(arr, size, value);
                  break;
                  }
                  case 5:
                        cout << "Exiting...\n";
                  break;

                  default:
                        cout << "Invalid option. Try again.\n";
            }
      } while (op != 5);

      return 0;
}
