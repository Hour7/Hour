#include <iostream>
using namespace std;

// Function to search for duplicates in the array
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

// Function to find and display non-duplicate elements
void searchNonDuplicates(int arr[], int size) {
    cout << "Non-duplicate elements: ";
    bool isDuplicate;
    for (int i = 0; i < size; i++) {
        isDuplicate = false;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    const int MAX_SIZE = 10;
    int arr[MAX_SIZE], size, value, option;

    cout << "Enter size (max " << MAX_SIZE << "): ";
    cin >> size;

    if (size > MAX_SIZE) {
        cout << "Array size exceeds maximum allowed size!" << endl;
        return 1;
    }

    for (int i = 0; i < size; i++) {
        cout << "Enter element [" << i << "]: ";
        cin >> arr[i];
    }

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Search duplicates" << endl;
        cout << "2. Find non-duplicates" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter value to find duplicates: ";
                cin >> value;
                searchDuplicates(arr, size, value);
                break;

            case 2:
                searchNonDuplicates(arr, size);
                break;

            case 0:
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
