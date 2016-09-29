
#include <iostream>
#include <stdexcept>
#include "Executive.h"
#include "MathTools.h"
#include "NegativeDiscriminant.h"
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"

void Executive::run()
{
    int choice = 0;


    while (choice != 4)
    {
        try
        {
            choice = menu();

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
            std::cout << e.what() << std::endl;
        }
        catch(CannotDetermineRoomDimensions& e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(NegativeDiscriminant& e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(std::runtime_error& e)
        {
            std::cout << "UNEXPECTED RUNTIME ERROR: " << e.what() << std::endl;
        }

        std::cout << std::endl;
    }
}

int Executive::menu()
{
    int choice = 0;

    do
    {
        std::cout << "Select One:" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "1. Quaratic Solver: Enter A, B, and C" << std::endl;
        std::cout << "2. Line Intersecting Unit Circle: Enter d, e, and f" <<
        std::endl;
        std::cout << "3. Calculate Room Dimensions: Enter A and E" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << std::endl;

        std::cout << "Choice: ";
        std::cin >> choice;

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

void Executive::quadraticSolver()
{
    MathTools Utility;

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double* roots = new double[2];
    int result = 0;


    std::cout << "Enter A, B, and C:" << std::endl;
    std::cout << "A: ";
    std::cin >> a;
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


    result = Utility.solveQuadratic(a, b, c, roots);

    if (result == 1)
        std::cout << "There is one root:" << std::endl;
    else
        std::cout << "There are 2 roots:" << std::endl;

    for (int x = 0; x < result; x++)
    {
        std::cout << "Root " << x+1 << ": " << roots[x] <<
        std::endl;
    }

    delete[] roots;
}

void Executive::intersectFinder()
{
    MathTools Utility;

    double d = 0.0;
    double e = 0.0;
    double f = 0.0;
    double intersections;
    double** pts = new double*[2];
    pts[0] = new double[2];
    pts[1] = new double[2];

    std::cout << "Enter d, e, and f for the equation dx + ey + f = 0:"
    << std::endl;
    std::cout << "d: ";
    std::cin >> d;
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

    intersections = Utility.intersectLineUnitCircle(d, e, f, pts);

    if(intersections == 1)
        std::cout << "There is one intersecion:" << std::endl;
    else
        std::cout << "There are two intersections:" << std::endl;

    for (int x = 0; x < intersections; x++)
    {
        std::cout << "Intersection " << x+1 << ": (" << pts[x][0] <<
        ", " << pts[x][1] << ")" << std::endl;
    }

    delete[] pts[0];
    delete[] pts[1];
    delete[] pts;
}

void Executive::roomSizeFinder()
{
    MathTools Utility;

    double area = 0.0;
    double extra = 0.0;
    double length = 0.0;
    double width = 0.0;
    double minLength = 0.0;

    std::cout << std::endl;
    std::cout << "Room Dimension Finder:" << std::endl;
    std::cout << "Enter desired room area: ";
    std::cin >> area;
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
    while ( std::cin.fail() )
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl;
        std::cout << "Bad input, try again." << std::endl << std::endl;
        std::cout << "Enter minimum length for the room: ";
        std::cin >> minLength;
    }
    std::cout << std::endl;

    Utility.roomDimensions(area, extra, minLength, width, length);

    std::cout << "Room Dimensions:" << std::endl;
    std::cout << "Length: " << length << std::endl;
    std::cout << "Width: " << width << std::endl;
}
