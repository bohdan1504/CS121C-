//////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Spring 2025									//
//																					//
//	Type of Assignment: Lab 7		 												//
//	Section Number: 703		 														//
//	Author: Bohdan Andrashko					    								//
//	Date Assigned: Feb 24, 2025			 											//
//	Project Name: Geometry Calculator   											//
//																					//
// Purpose of Program:	Menu-like program that asks user to select the type of      //
//        geometry calculaton. User then is prompted values and receives            //
//        computed output. Program uses custom functions for calculations.          //
//																					//
// Algothrim:																		//
//	1.	Loop program until user quits 												//
//  2.	Display menu options to calculate Rectangle, Triangle, Cirlce or Quit		//
//  3.	Ask user to select an option												//
//  4.	Validate user input to be within 1 to 4										//
//  5.	Perform calculation based on user selection									//
//  6.	Display results																//
//  7.	Repeat steps 1 to 6 until user quits									    //
//////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// Constant Declarations
const double PI = 3.14159;

// Variable Declarations
double base, height, // variables for triangle
    radius,          // variable for circle
    width, lenght;   // variables for rectangle
double area;
int choice;

// Function declaration
void showMenu();
double rectangle(double length, double width);
double triangle(double base, double height);
double circle(double radius);

void showMenu(){
    cout << "\nGeometry Calculator\n\n"
         << "1. Calculate the Area of a Rectangle\n"
         << "2. Calculate the Area of a Circle\n"
         << "3. Calculate the Area of a Triangle\n"
         << "4. Quit\n\n"
         << "Enter your choice (1-4): ";

    // Prompt for user option input
    cin >> choice;
}

double rectangle(double length, double width){
    return length * width;}

double triangle(double base, double height){
    return 0.5 * base * height;}

double circle(double radius){
    const double PI = 3.14159;
    return PI * pow(radius, 2);}

// function to validate the input
int inputValidation(){
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(100, '\n');
        return 1;
    }
    return 0;
}

int continueProgram()
{
    string response;
    cout << "Would you like to continue? (Y/N): ";
    cin >> response;
    while (response != "Y" && response != "y" && response != "N" && response != "n")
    {
        cout << "Please enter a valid response (Y/N): ";
        cin >> response;
    }
    if (response == "N" || response == "n")
    {
        return 0;
    }
    return 1;
}

// Main Program
int main(){


    // Output Identification
    cout << "Lab 7 by Bohdan Andrashko - "
         << "Geometry Calculator (with functions)\n";

    // Program loop to allow the user to repeat the operation
    do
    {
        // Display the menu
        showMenu();

        // Input validation. If the choice is not within 1 to 4, reenter
        while (inputValidation() || choice < 1 || choice > 4)
        {
            cout << "Please enter a valid choice (1-4): ";
            cin >> choice;
        }

        // Switch statement to perform the calculation based on user input
        switch (choice)
        {
        case 1: // calculate the area of a rectangle
            // Prompt for user input of length
            cout << "Enter the length of the rectangle: ";
            cin >> lenght;

            // Input validation
            while (inputValidation() || lenght <= 0)
            {
                cout << "Please enter a valid length: ";
                cin >> lenght;
            }

            // Prompt for user input of width
            cout << "Enter the width of the rectangle: ";
            cin >> width;

            // Input validation
            while (inputValidation() || width <= 0)
            {
                cout << "Please enter a valid width: ";
                cin >> width;
            }

            // Calculate area
            area = rectangle(lenght, width);

            // Display results
            cout << "The area of the rectangle is " << area << endl;

            // Ask user if they would like to continue
            if (continueProgram() == 0)
            {
                choice = 4;
            }

            break;

        case 2: // calculate the area of a circle
            // Prompt for user input of radius
            cout << "Enter the radius of the circle: ";
            cin >> radius;

            // Input validation
            while (inputValidation() || radius <= 0)
            {
                cout << "Please enter a valid radius: ";
                cin >> radius;
            }

            // Calculate area
            area = circle(radius);

            // Display results
            cout << "The area of the circle is " << area << endl;

            // Ask user if they would like to continue
            if (continueProgram() == 0)
            {
                choice = 4;
            }

            break;

        case 3: // calculate the area of a triangle
            // Prompt for user input of base of the triangle
            cout << "Enter the base of the triangle: ";
            cin >> base;

            // Input validation
            while (inputValidation() || base <= 0)
            {
                cout << "Please enter a valid base: ";
                cin >> base;
            }

            // Prompt for user input of height
            cout << "Enter the height of the triangle: ";
            cin >> height;

            // Input validation
            while (inputValidation() || height <= 0)
            {
                cout << "Please enter a valid height: ";
                cin >> height;
            }

            // Calculate area
            area = triangle(base, height);

            // Display results
            cout << "The area of the triangle is " << area << endl;

            // Ask user if they would like to continue
            if (continueProgram() == 0)
            {
                choice = 4;
            }

            break;

        case 4:
            cout << "You choose to quit.\n";
            break;
        }
    } while (choice != 4); // Ends loop if user inputs "4" as an option

    cout << "\n\nEnd Program.\n";

    return 0;
}