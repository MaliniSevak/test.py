#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayColors(const vector<string>& colors) {
    cout << "Available colors:\n";
    for (size_t i = 0; i < colors.size(); ++i) {
        cout << i + 1 << ". " << colors[i] << endl;
    }
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // List of colors
    vector<string> colors = {"Red", "Green", "Blue", "Yellow", "Purple", "Orange"};
    
    // Randomly select a color
    string selectedColor = colors[rand() % colors.size()];

    cout << "Welcome to the Color Guessing Game!\n";
    displayColors(colors);

    string userGuess;
    int attempts = 0;
    const int maxAttempts = 3;

    while (attempts < maxAttempts) {
        cout << "Guess the color (Attempt " << attempts + 1 << " of " << maxAttempts << "): ";
        cin >> userGuess;

        // Convert user input to lowercase for case-insensitive comparison
        for (auto &c : userGuess) c = tolower(c);
        string lowerSelectedColor = selectedColor;
        for (auto &c : lowerSelectedColor) c = tolower(c);

        if (lowerSelectedColor == userGuess) {
            cout << "Congratulations! You guessed the color: " << selectedColor << "!\n";
            break;
        } else {
            cout << "Wrong guess! Try again.\n";
            attempts++;
        }
    }

    if (attempts == maxAttempts) {
        cout << "Sorry! You've used all your attempts. The correct color was: " << selectedColor << ".\n";
    }

    cout << "Thank you for playing!\n";
    return 0;
}