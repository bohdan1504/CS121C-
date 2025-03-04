//////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Spring 2025									//
//																					//
//	Type of Assignment: Lab 7		 												//
//	Section Number: 703		 														//
//	Author: Bohdan Andrashko					    								//
//	Date Assigned: Feb 24, 2025			 											//
//	Project Name: The Sum, the Largest and the Smallest   							//
//																					//
// Purpose of Program:	Program to find the sum, the largest and Smallest.          //
//																					//
// Algothrim:																		//
//	1. Generate 10 random numbers between -20 to 20.                                //
//  2. a function randomInt(int, int) should be defined and called.                 //
//  3. Count the numbers of positive numbers, and negative                          //
//  4. Calculate the sum of all the numbers                                         //
//  5. Calculate the average of all the numbers.                                    //
//  6. Find the largest and smallest numbers generated. 				     	    //
//  7. Display the results.													        //
//  8. Ask user if they would like to continue. If yes, repeat the process.         //
//  9. End program if user chooses to quit.                                         //
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

// Function declaration
int randomInt(int, int);

int main()
{
    int positive = 0, negative = 0, sum = 0, largest = 0, smallest = 0;
    float avarage;
    char choice;

    // Output Identification
    cout << "Lab 7 by Bohdan Andrashko - "
         << "The Sum, the Largest and the Smallest\n";

    cout << "\nThe 10 random numbers are: " << endl;

    // Generate and display 10 random numbers between -20 and 20
    for (int i = 0; i < 10; ++i)
    {
        int num = randomInt(-20, 20); // Generate random number between -20 and 20
        cout << num << " ";
        if (num > 0)
        {
            positive++;
        }
        else if (num < 0)
        {
            negative++;
        }

        // Find the largest and smallest numbers
        if (num > largest)
        {
            largest = num;
        }
        if (num < smallest)
        {
            smallest = num;
        }

        // Calculate the sum
        sum += num;
    }
    cout << endl;
    ;
    // Calculate the average with 1 floating point precision
    avarage = static_cast<float>(sum) / 10;
    cout << fixed << setprecision(1);

    // Display the results
    cout << "\nThere were a total of " << positive << " positive numbers entered" << endl;
    cout << "There were a total of " << negative << " negative numbers entered" << endl
         << endl;

    cout << "The sum of all the numbers: " << sum << endl;
    cout << "The average of all the numbers: " << avarage << endl;
    cout << "The largest number: " << largest << endl;
    cout << "The smallest number: " << smallest << endl;

    // Ask user if they would like to continue
    cout << "\nWould you like to do it again? (Y/N): ";
    cin >> choice;

    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n' || cin.fail())
    {
        cin.clear();                                   // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n');                        // ignore last input
        cout << "Please enter a valid choice (Y/N): "; // prompt user to enter a valid choice
        cin >> choice;                                 // get user input
    }

    while (choice == 'Y' || choice == 'y') // if user wants to continue
    {
        main(); // call main function
    }
    if (choice == 'N' || choice == 'n') // if user wants to quit
    {
        choice = 0;             // set choice to 0
        cin.clear();            // clear input buffer to restore cin to a usable state
        cin.ignore(1000, '\n'); // ignore last input

        cout << "You choose to quit.\n"; // display message
        return 0;                        // end program
    }

    return 0;
}

// Function to generate random numbers
int randomInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}
