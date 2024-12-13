#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void showArray(int arr[], int size) {
      cout << "Array elements:\n";
      for (int i = 0; i < size; i++) {
            cout << "[" << i << "]: " << arr[i] << endl;
      }
}

int insertElement(int arr[], int size, int pos, int value) {
      if (pos < 0 || pos > size || size >= MAX_SIZE) {
            cout << "Invalid position or array is full!\n";
            return size;
      }
      for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
      }
      arr[pos] = value;
      return size + 1;
}

int deleteByPosition(int arr[], int size, int pos) {
      if (pos < 0 || pos >= size) {
            cout << "Invalid position!\n";
            return size;
      }
      for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
      }
      return size - 1;
}




int deleteByValue(int arr[], int size, int value) {
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
      return size;
}

void searchFirstOccurrence(int arr[], int size, int value) {
      for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                  cout << "Found " << value << " at index " << i << ".\n";
                  return;
            }
      }
      cout << value << " not found in the array.\n";
}

void searchDuplicates(int arr[], int size, int value) {
      bool found = false;
      cout << "Duplicates of " << value << ": ";
      for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                  cout << i << " ";
                  found = true;
            }
      }
      if (!found) {
            cout << "None";
      }
      cout << endl;
}

int main() {
      int arr[MAX_SIZE], size = 0, option, pos, value;

      while (true) {
            cout << "Menu:"<<endl;
            cout << "1. Input array"<<endl;
            cout << "2. Show array"<<endl;
            cout << "3. Insert element"<<endl;
            cout << "4. Delete by position"<<endl;
            cout << "5. Delete by value";
            cout << "6. Search first occurrence"<<endl;
            cout << "7. Search duplicates"<<endl;
            cout << "0. Exit"<<endl;
            cout << "Choose an option: ";cin >> option;

            switch (option) {
                  case 1:
                        cout << "Enter size (max " << MAX_SIZE << "): ";
                        cin >> size;
                        if (size > MAX_SIZE) {
                              cout<<"Array is full"<<endl;
                              break;
                        }
                        for (int i = 0; i < size; i++) {
                              cout << "Enter element [" << i << "]: ";
                              cin >> arr[i];
                        }
                  break;

                  case 2:
                        showArray(arr, size);
                  break;

                  case 3:
                        cout << "Enter position (0-" << size << "): ";cin >> pos;
                        cout << "Enter value: ";cin >> value;
                        size = insertElement(arr, size, pos, value);
                  break;

                  case 4:
                        cout << "Enter position (0-" << size - 1 << "): ";
                        cin >> pos;
                        size = deleteByPosition(arr, size, pos);
                  break;

                  case 5:
                        cout << "Enter value to delete: ";
                        cin >> value;
                        size = deleteByValue(arr, size, value);
                  break;

                  case 6:
                        cout << "Enter value to search: ";
                        cin >> value;
                        searchFirstOccurrence(arr, size, value);
                  break;

                  case 7:
                        cout << "Enter value to find duplicates: ";
                        cin >> value;
                        searchDuplicates(arr, size, value);
                  break;

                  case 0:
                        cout << "Goodbye!\n";
                  return 0;

                  default:
                        cout << "Invalid option. Try again.\n";
            }
      }
}
