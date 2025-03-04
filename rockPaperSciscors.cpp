
//////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Spring 2025									//
//																					//
//	Type of Assignment: Lab 7		 												//
//	Section Number: 703		 														//
//	Author: Bohdan Andrashko					    								//
//	Date Assigned: Feb 24, 2025			 											//
//	Project Name: Rock, Paper, Sciscors                    							//
//																					//
// Purpose of Program:	Program that lets the user play the game of Rock, Paper,    //
//                      Scissors against the computer.                              //
//																					//
// Algothrim:																		//
//	1. Display the menu options for Rock, Paper, Scissors and Quit.                 //
//  2. Ask user to select an option.                                                //
//  3. Validate user input to be within 1 to 4.                                     //
//  4. Perform calculation based on user selection.                                 //
//  5. Display results.                                                             //
//  6. Repeat steps 1 to 6 until user quits.                                        //
//  7. End program.                                                                 //
//																					//
//////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes
int getUserChoice(); // void getUserChoice ( int&  );  is the alternate prototype
int getComputerChoice();
void determineWinner(int, int);
void displayChoice(int);

// Variable Declarations

int choiceInt;
int main()
{
    int userChoice, computerChoice;
    char choiceChar = 'N';

    // Output Identification
    cout << "Lab 7 by Bohdan Andrashko - "
         << "Rock, Paper, Scissors\n";

    // Program loop to allow the user to repeat the operation
    do
    {
        // Display the menu
        cout << "\nGame Menu\n---------\n"
             << "1. Rock\n"
             << "2. Paper\n"
             << "3. Scissors\n"
             << "4. Quit\n\n"
             << "Enter your choice (1-4): ";

        // Input validation. If the choice is not within 1 to 4, reenter
        userChoice = getUserChoice();
        if (userChoice == 4)
        {
            cout << "You choose to quit.\n";
            return 0;
        }
        computerChoice = getComputerChoice();

        // Display the choices
        displayChoice(userChoice);
        displayChoice(computerChoice);

        // Determine the winner
        determineWinner(userChoice, computerChoice);

        // Ask user if they would like to continue
        cout << "\nWould you like to do it again? (Y/N): ";
        cin >> choiceChar;

        while (choiceChar != 'Y' && choiceChar != 'y' && choiceChar != 'N' && choiceChar != 'n' || cin.fail())
        {
            cin.clear();                                   // clear input buffer to restore cin to a usable state
            cin.ignore(1000, '\n');                        // ignore last input
            cout << "Please enter a valid choice (Y/N): "; // prompt user to enter a valid choice
            cin >> choiceChar;                             // get user input
        }

    } while (choiceChar == 'Y' || choiceChar == 'y'); // Repeat if user wants to continue

    cout << "\n\nEnd Program.\n";

    return 0;
}

// Function Definitions
// Get the user's choice
int getUserChoice()
{
    cin >> choiceInt;
    while (choiceInt < 1 || choiceInt > 4 || cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please enter a valid choice (1-4): ";
        cin >> choiceInt;
    }
    return choiceInt;
}

// Generate a random number for the computer
int getComputerChoice()
{
    return rand() % 3 + 1;
}

// Determine the winner
void determineWinner(int user, int computer)
{
    if (user == computer)
    {
        cout << "It's a tie!\n";
    }
    else if (user == 1 && computer == 3 || user == 2 && computer == 1 || user == 3 && computer == 2)
    {
        cout << "You win!\n";
    }
    else
    {
        cout << "Computer wins!\n";
    }
}

// Display the choice
void displayChoice(int choice)
{
    switch (choice)
    {
    case 1:
        cout << "Rock\n";
        break;
    case 2:
        cout << "Paper\n";
        break;
    case 3:
        cout << "Scissors\n";
        break;
    }
}

// End of Program
