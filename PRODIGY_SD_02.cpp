#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    // Generate random number between 1 and 100
    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;
    cout << "                        NUMBER GUESSING GAME                " << endl;
    cout << "                #   Welcome to the game of numbers.   #" << endl;
    cout << endl;
    cout << "                         ****INSTRUCTIONS****           " << endl;
    cout << "1. You will be provided with a Random number between 1 to 100. Your task is to guess the correct number." << endl
         << "2. Your total number of trials are being counted." << endl
         << "3. Person with least trials win." << endl
         << "4. You will be provided hints while playing the game." << endl;
    cout << "I have generated a random number between 1 and 100. Guess it." << endl
         << "YOUR TIME BEGINS NOW." << endl;

    do
    {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > randomNumber)
        {
            cout << "Your guess is too high." << endl;
        }
        else if (guess < randomNumber)
        {
            cout << "Your guess is too low." << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    } while (guess != randomNumber);

    return 0;
}