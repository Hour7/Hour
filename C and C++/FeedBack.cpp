#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to collect feedback
void collectFeedback() {
    int rating;
    string comments;

    cout << "\nThank you for using the Bus Reservation System!\n";
    cout << "We'd love to hear your feedback.\n";
    cout << "Please rate your experience from 1 (worst) to 5 (best): ";
    cin >> rating;

    // Validate rating input
    while (rating < 1 || rating > 5) {
        cout << "Invalid rating. Please enter a number between 1 and 5: ";
        cin >> rating;
    }

    cout << "Please leave any additional comments: ";
    cin.ignore();  // To ignore leftover newline character in the input buffer
    getline(cin, comments);

    // Save feedback to file
    ofstream feedbackFile("feedback.txt", ios::app); // Open in append mode
    if (feedbackFile.is_open()) {
        feedbackFile << "Rating: " << rating << "/5\n";
        feedbackFile << "Comments: " << comments << "\n";
        feedbackFile << "------------------------\n";
        feedbackFile.close();
        cout << "Thank you for your feedback!\n";
    } else {
        cerr << "Error opening feedback file.\n";
    }
}

// Main menu or exit function
void exitProgram() {
    collectFeedback();
    cout << "Exiting the program. Goodbye!\n";
    exit(0);
}

// Example of main program structure
int main() {
    int choice;

    do {
        cout << "1. Reserve a ticket\n";
        cout << "2. View trips\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Reservation logic here
                cout << "Reserving ticket...\n";
                break;
            case 2:
                // View trips logic here
                cout << "Displaying trips...\n";
                break;
            case 3:
                exitProgram(); // Call exit program with feedback
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
