
#include <iostream>
#include <stdexcept>
#include "Executive.h"
#include "MathTools.h"
#include "NegativeDiscriminant.h"
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"

void Executive::run()
{
    MathTools Utility;
    int choice = 0;

    choice = menu();

    if (choice == 1)
    {
        double a = 0.0;
        double b = 0.0;
        double c = 0.0;
        double* roots = new double[2];
        int result = 0;


        std::cout << "Enter A, B, and C:" << std::endl;
        std::cout << "A: ";
        std::cin >> a;
        std::cout << "B: ";
        std::cin >> b;
        std::cout << "C: ";
        std::cin >> c;
        std::cout << std::endl;


        result = Utility.solveQuadratic(a, b, c, roots);

        if (result == 0)
        {
            std::cout << "There are no real roots." << std::endl;
        }
        else
        {
            std::cout << "There are " << result << " roots:" << std::endl;

            for (int x = 0; x < result; x++)
            {
                std::cout << "Root " << x+1 << ": " << roots[x] <<
                std::endl;
            }
        }

    }
    else if (choice == 2)
    {
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
        std::cout << "e: ";
        std::cin >> e;
        std::cout << "f: ";
        std::cin >> f;

        //try
        //{
        intersections = Utility.intersectLineUnitCircle(d, e, f, pts);

        std::cout << "There are " << intersections << " intersections."
        << std::endl;

        for (int x = 0; x < intersections; x++)
        {
            std::cout << "Intersection " << x << ": (" << pts[x][0] <<
            ", " << pts[x][1] << ")" << std::endl;
        }
        //}

    }
    else if(choice == 3)
    {

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
        else if (choice < 1 || choice > 3)
        {
            std::cout << "Invalid choice. Try again." << std::endl;
            std::cout << std::endl;
        }
    } while (choice < 1 || choice > 3);

    return(choice);
}
