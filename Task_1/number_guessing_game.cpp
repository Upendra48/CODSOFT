//? Task 1 of C++ Programming Internship at Codsoft 

//* Number Guessing Game

//todo:  Using procedural programming
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


//todo: Using object oriented programming

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class GuessGame
{
    private:
        int number, guess, tries = 0;

    public:
        GuessGame():tries(0)
        {
            srand(time(0)); //seed random number generator
            number = rand() % 100 + 1; // random number between 1 and 100
        }

        void play()
        {
            cout << "Guess My Number Game\n\n";
            do 
            {
                getGuess();
                checkGuess();
            } while (guess != number);    // until guess is correct
        }
    private:    
        void getGuess()
        {
            cout << "Enter a guess between 1 and 100 : \n";
            cout << "Enter 0 to exit the game  :  \n";
            cin >> guess;
            if (guess == 0)
            {
                cout << "Thank you for playing the game!\n";
                exit(0);
            }
            else
            if(guess < 1 || guess > 100)
            {
                cout << "Invalid guess! Please enter a guess between 1 and 100.\n\n";    // if guess is out of range
                getGuess();
            }
        }
        void checkGuess()
        {
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
        }
};

int main() 
{
    GuessGame game;
    game.play();
    cout << "Thank you for playing the game!\n";
    return 0;
}
