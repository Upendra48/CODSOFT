// Task 1 of C++ Programming Internship with Codsoft 
// Number Guessing Game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    int number, guess, tries = 0;
    srand(time(0)); //seed random number generator
    number = rand() % 100 + 1; // random number between 1 and 100
    cout << "Guess My Number Game\n\n";
    do 
    {
        cout << "Enter a guess between 1 and 100 : ";
        cin >> guess;
        if(guess < 1 || guess > 100)
        {
            cout << "Invalid guess! Please enter a guess between 1 and 100.\n\n";    // if guess is out of range
            continue;
        }
        tries++;
        if (guess > number)
        {
            cout << "Too high!\n\n";    // if guess is too high
        }
        else if (guess < number)
        {
            cout << "Too low!\n\n";     // if guess is too low
        }
        else
        {
            cout << "\nCorrect! You got it in " << tries << " guesses!\n";     // if guess is correct
        }
    } while (guess != number);    // until guess is correct

    return 0;
}