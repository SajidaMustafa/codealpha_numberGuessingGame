#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int GenerateSecretNumber(int lowerBound, int upperBound) {
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}
void StartGame(int lowerBound, int upperBound, int maxTry) {
    int guess, attempts = 1;
    int secretNumber = GenerateSecretNumber(lowerBound, upperBound);
    cout << "I have selected a number between " << lowerBound << " and " << upperBound << ". Try to guess it." << endl;
    do {
        if (attempts > maxTry) {
            cout << "Failed to guess the number in attempts: " << maxTry << endl;
            break;
        }
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "Congratulations! You've guessed the correct number (" << secretNumber << ") in " << attempts - 1 << " attempts." << endl;
        }

    } while (guess != secretNumber);
}

int main() {
    srand(time(0));
    int choice;
    bool run = true;
    int lowerBound, upperBound, secretNumber,maxTry=0;
    while (run != false) {
        cout <<"_________________________________________________________________" << endl;
        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "Press 1 to Start the Game..." << endl;
        cout << "Press 2 to Exit the Game..." << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter the range for the number" << endl;
            cout << "Enter lower bound: ";
            cin >> lowerBound;
            cout << "Enter upper bound: ";
            cin >> upperBound;
            cout << "Enter Maximum tries: ";
            cin >> maxTry;
            StartGame(lowerBound, upperBound,maxTry);
        }
        else if (choice == 2) {
            run = false;
        }
        else {
            cout << "You entered an invalid choice...!" << endl;
        }
        
    }
    return 0;
}
