
#include <iostream>
#include "Executive.h"

void Executive::run()
{

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
        std::endl;

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
    } while (choice < 1 || choice > 3)

    return(choice);
}
