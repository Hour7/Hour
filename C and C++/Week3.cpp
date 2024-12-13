#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int arr[MAX_SIZE];
int SIZE = 0;

void showArray() {
    if (SIZE == 0) {
        cout << "Array is empty." << endl;
    } else {
        cout << "Array elements: ";
        for (int i = 0; i < SIZE; i++) {
            cout << "Array " << i << " : " << arr[i] << endl;
        }
    }
}

void insertElement(int value) {
    if (SIZE >= MAX_SIZE) {
        cout << "Array is full. Cannot insert more elements." << endl;
        return;
    }
    int pos = 0;
    while (pos < SIZE && arr[pos] < value) {
        pos++;
    }
    for (int i = SIZE; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    SIZE++;
    cout << "Inserted " << value << " into the array." << endl;
}

void deleteElement(int value) {
    int pos = -1;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == value) {
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        cout << "Element " << value << " not found in the array." << endl;
        return;
    }
    for (int i = pos; i < SIZE - 1; i++) {
        arr[i] = arr[i + 1];
    }
    SIZE--;
    cout << "Deleted " << value << " from the array." << endl;
}

void binarySearch(int value) {
    int left = 0, right = SIZE - 1, mid;
    bool found = false;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == value) {
            found = true;
            cout << "Element " << value << " found at index " << mid << "." << endl;
            break;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        cout << "Element " << value << " not found in the array." << endl;
    }
}

int main() {
    int choice, value;
    cout << "Enter the SIZE of the array (max 10): ";
    cin >> SIZE;
    if (SIZE > 20 || SIZE <= 0) {
        cout << "Invalid SIZE! Exiting program." << endl;
        return 0;
    }
    cout << "Enter " << SIZE << " elements for the array:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Element " << i << ": ";
        cin >> arr[i];
    }
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Show Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Binary Search\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                showArray();
                break;
            case 2:
                cout << "Enter the element to insert: ";
                cin >> value;
                insertElement(value);
                break;
            case 3:
                cout << "Enter the element to delete: ";
                cin >> value;
                deleteElement(value);
                break;
            case 4:
                cout << "Enter the element to search: ";
                cin >> value;
                binarySearch(value);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
