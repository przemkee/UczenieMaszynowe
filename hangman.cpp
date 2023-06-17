#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

using namespace std;

// Funkcja czyszcząca terminal w systemie Windows
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Funkcja wyświetlająca aktualny stan gry
void displayGameState(const string& guessedWord, int attempts) {
    cout << "Word: " << guessedWord << endl;
    cout << "Attempts remaining: " << attempts << endl;
}

// Funkcja sprawdzająca, czy dana litera jest częścią słowa
bool checkLetter(const string& word, string& guessedWord, char letter, int& remainingLetters) {
    bool correctGuess = false;

    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter && guessedWord[i] == '_') {
            guessedWord[i] = letter;
            remainingLetters--;
            correctGuess = true;
        }
    }

    return correctGuess;
}

int main() {
    // Czyszczenie terminala
    clearScreen();

    // Podanie słowa przez pierwszego gracza
    string word;
    cout << "Player 1, enter a word (up to 5 letters): ";
    cin >> word;

    // Czyszczenie terminala
    clearScreen();

    // Inicjalizacja zmiennych
    int attempts = 15;
    string guessedWord(word.length(), '_');
    int remainingLetters = word.length();

    // Rozpoczęcie gry
    cout << "Welcome to Hangman!" << endl;

    while (attempts > 0 && remainingLetters > 0) {
        displayGameState(guessedWord, attempts);

        // Pobranie litery od drugiego gracza
        char letter;
        cout << "Player 2, guess a letter: ";
        cin >> letter;

        // Sprawdzenie, czy litera jest częścią słowa
        if (checkLetter(word, guessedWord, letter, remainingLetters)) {
            cout << "Correct guess!" << endl;
        } else {
            cout << "Wrong guess!" << endl;
            attempts--;
        }
    }

    // Wyświetlenie wyniku gry
    if (remainingLetters == 0) {
        cout << "Congratulations! Player 2 won!" << endl;
    } else {
        cout << "Game over! Player 1's word was: " << word << endl;
    }

    return 0;
}
