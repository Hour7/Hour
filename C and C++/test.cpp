#include <iostream>
using namespace std;

void showelement(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Array element " << i << ": " << arr[i] << endl;
    }
}

void duplicate_search(int arr[], int size) {
    int search;
    cout << "Enter the number to search for duplicates: ";
    cin >> search;
    bool found = false;

    cout << "Duplicate occurrences: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] == search) {
            cout << arr[i] << " (index: " << i << ") ";
            found = true;
        }
    }
    if (!found) {
        cout << "No duplicates found for " << search << ".";
    }
    cout << endl;
}

void none_duplicate(int arr[], int size) {
    int search;
    cout << "Enter the number to search: ";
    cin >> search;

    for (int i = 0; i < size; i++) {
        if (arr[i] == search) {
            cout << "First occurrence: " << arr[i] << " (index: " << i << ")" <<endl;
            return; // Exit after finding the first occurrence
        }
    }
    cout << "Number " << search << " not found in the array." << endl;
}

int main() {
    int arr[10];
    int size = 0; // Default size to 0 to track initialization
    int op;
    bool initialized = false;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input array\n";
        cout << "2. Show array elements\n";
        cout << "3. Find first occurrence (non-duplicate search)\n";
        cout << "4. Find all duplicates\n";
        cout << "0. Exit\n";
        cout << "Enter the option: ";
        cin >> op;

        switch (op) {
            case 1:
                cout << "Input the size of the array (max 10): ";
                cin >> size;
                if (size > 10) {
                    cout << "Size cannot exceed 10. Setting to 10.\n";
                    size = 10;
                }
                for (int i = 0; i < size; i++) {
                    cout << "Array[" << i << "]: ";
                    cin >> arr[i];
                }
                initialized = true;
                break;

            case 2:
                if (initialized) {
                    showelement(arr, size);
                } else {
                    cout << "Array not initialized. Please choose option 1 first.\n";
                }
                break;

            case 3:
                if (initialized) {
                    none_duplicate(arr, size);
                } else {
                    cout << "Array not initialized. Please choose option 1 first.\n";
                }
                break;

            case 4:
                if (initialized) {
                    duplicate_search(arr, size);
                } else {
                    cout << "Array not initialized. Please choose option 1 first.\n";
                }
                break;

            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (op != 0);

    return 0;
}