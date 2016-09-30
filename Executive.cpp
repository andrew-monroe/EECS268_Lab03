/**
*	@file Executive.cpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Implementation file for Executive class. Contains the code for all
        user input and system output. Creates MathTools class variable to use
        MathTools methods.
*/

#include <iostream>
#include <stdexcept>
#include <limits>
#include "Executive.h"
#include "MathTools.h"
#include "NegativeDiscriminant.h"
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"

/*
    Runs the program. Calls menu method to get user decision on what to do.
    Calls appropriate method based on user's decision. Handles the possible
    exceptions. Loops until user quits.
*/
void Executive::run()
{
    //create and intialize choice variable
    int choice = 0;

    //loops until user chooses to quit
    while (choice != 4)
    {
        //contains all exception-throwing code
        try
        {
            //get user choice by calling menu method
            choice = menu();

            //calls the appropriate method based on the user's choice
            if (choice == 1)
            {
                quadraticSolver();
            }
            else if (choice == 2)
            {
                intersectFinder();
            }
            else if(choice == 3)
            {
                roomSizeFinder();
            }
        }
        catch(NoIntersection& e)
        {
            //the line didn't intersect the circle
            std::cout << e.what() << std::endl;
        }
        catch(CannotDetermineRoomDimensions& e)
        {
            //the user's room specifications weren't possible
            std::cout << e.what() << std::endl;
        }
        catch(NegativeDiscriminant& e)
        {
            //the discriminant of the quadratic equation was negative
            std::cout << e.what() << std::endl;
        }
        catch(std::runtime_error& e)
        {
            //this is here in case something goes wrong
            std::cout << "UNEXPECTED RUNTIME ERROR: " << e.what() << std::endl;
        }

        std::cout << std::endl;
    }
}

/*
    Prints out the menu of options for the user. Returns the user's choice.
*/
int Executive::menu()
{
    int choice = 0;

    //loop until user selects a valid choice
    do
    {
        //output menu
        std::cout << "Select One:" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "1. Quaratic Solver: Enter A, B, and C" << std::endl;
        std::cout << "2. Line Intersecting Unit Circle: Enter d, e, and f" <<
        std::endl;
        std::cout << "3. Calculate Room Dimensions: Enter A and E" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << std::endl;

        //receive user choice
        std::cout << "Choice: ";
        std::cin >> choice;

        //ensures user entered a valid choice
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Try again. "<< std::endl;
            std::cout << std::endl;
            choice = 0;
        }
        else if (choice < 1 || choice > 4)
        {
            std::cout << "Invalid choice. Try again." << std::endl;
            std::cout << std::endl;
        }
    } while (choice < 1 || choice > 4);

    return(choice);
}

/*
    Gathers user input to solve for the roots in a quadratic equation. Calls
    MathTools method to solve the eqaution with the user's values. Outputs the
    results.
*/
void Executive::quadraticSolver()
{
    //create the MathTools class variable
    MathTools Utility;

    //create and intialize other necessary variables
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double* roots = new double[2];
    int result = 0;

    //gather user input of quadratic equation variables with error checking
    std::cout << "Enter A, B, and C:" << std::endl;
    std::cout << "A: ";
    std::cin >> a;
    //validity check
    while ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Bad input, try again." << std::endl << std::endl;
        std::cout << "A: ";
        std::cin >> a;
    }

    std::cout << "B: ";
    std::cin >> b;
    //validity check
    while ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Bad input, try again." << std::endl << std::endl;
        std::cout << "B: ";
        std::cin >> b;
    }

    std::cout << "C: ";
    std::cin >> c;
    //validity check
    while ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Bad input, try again." << std::endl << std::endl;
        std::cout << "C: ";
        std::cin >> c;
    }

    std::cout << std::endl;

    //call MathTools method to find the roots
    //can throw an exception if discriminant is negative
    result = Utility.solveQuadratic(a, b, c, roots);

    //output results
    if (result == 1)
        std::cout << "There is one root:" << std::endl;
    else
        std::cout << "There are 2 roots:" << std::endl;

    for (int x = 0; x < result; x++)
    {
        std::cout << "Root " << x+1 << ": " << roots[x] <<
        std::endl;
    }

    //delete array
    delete[] roots;
}


/*
    Gathers user input to solve for the intersection of a line with a unit
    circle. Calls MathTools method to find the intersection(s) using the user's
    values. Outputs the results.
*/
void Executive::intersectFinder()
{
    //create MathTools class variable
    MathTools Utility;

    //create and intialize other necessary variables
    double d = 0.0;
    double e = 0.0;
    double f = 0.0;
    double intersections;
    double** pts = new double*[2];
    pts[0] = new double[2];
    pts[1] = new double[2];

    //gather user inputs for the equation with error checking
    std::cout << "Enter d, e, and f for the equation dx + ey + f = 0:"
    << std::endl;

    std::cout << "d: ";
    std::cin >> d;
    //validity check
    while ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Bad input, try again." << std::endl << std::endl;
        std::cout << "d: ";
        std::cin >> d;
    }

    std::cout << "e: ";
    std::cin >> e;
    //validity check
    while ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Bad input, try again." << std::endl << std::endl;
        std::cout << "e: ";
        std::cin >> e;
    }

    std::cout << "f: ";
    std::cin >> f;
    //validity check
    while ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Bad input, try again." << std::endl << std::endl;
        std::cout << "f: ";
        std::cin >> f;
    }

    std::cout << std::endl;

    //call MathTools method to find intersection(s)
    //can throw exception if no intersection is found
    intersections = Utility.intersectLineUnitCircle(d, e, f, pts);

    //output results
    if(intersections == 1)
        std::cout << "There is one intersecion:" << std::endl;
    else
        std::cout << "There are two intersections:" << std::endl;

    for (int x = 0; x < intersections; x++)
    {
        std::cout << "Intersection " << x+1 << ": (" << pts[x][0] <<
        ", " << pts[x][1] << ")" << std::endl;
    }

    //delete 2D array
    delete[] pts[0];
    delete[] pts[1];
    delete[] pts;
}

/*
    Gather user input to find dimensions of a room of certain area with
    width being some user-specified amount greater than length. Calls MathTools
    method to perform calculations. Displays results.
*/
void Executive::roomSizeFinder()
{
    //create MathTools class variable
    MathTools Utility;

    //create and intialize other necessary variables
    double area = 0.0;
    double extra = 0.0;
    double length = 0.0;
    double width = 0.0;
    double minLength = 0.0;

    //gather user input with error checking
    std::cout << std::endl;
    std::cout << "Room Dimension Finder:" << std::endl;

    std::cout << "Enter desired room area: ";
    std::cin >> area;
    //validity check
    while ( std::cin.fail() || area < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Bad input, try again." << std::endl << std::endl;
        std::cout << "Enter desired room area: ";
        std::cin >> area;
    }

    std::cout << "Enter extra distance width has over length: ";
    std::cin >> extra;
    //validity check
    while ( std::cin.fail() || extra < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Bad input, try again." << std::endl << std::endl;
        std::cout << "Enter extra distance width has over length: ";
        std::cin >> extra;
    }

    std::cout << "Enter minimum length for the room: ";
    std::cin >> minLength;
    //validity check
    while ( std::cin.fail() || minLength < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Bad input, try again." << std::endl << std::endl;
        std::cout << "Enter minimum length for the room: ";
        std::cin >> minLength;
    }

    std::cout << std::endl;

    //call MathTools method to calculate room dimensions based on user's inputs
    //can throw exception if specifications are impossible
    Utility.roomDimensions(area, extra, minLength, width, length);

    //output results
    std::cout << "Room Dimensions:" << std::endl;
    std::cout << "Length: " << length << std::endl;
    std::cout << "Width: " << width << std::endl;
}
