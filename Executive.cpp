
#include "Executive.h"

void Executive::run()
{

}

int Executive::menu()
{
    int choice = 0;

    std::cout << "Select One:" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "1. Quaratic Solver: Enter A, B, and C" << std::endl;
    std::cout << "2. Line Intersecting Unit Circle: Enter d, e, and f" <<
        std::endl;
    std::cout << "3. Calculate Room Dimensions: Enter A and E" << std::endl;
    std::endl;

    std::cout << "Choice: ";
    std::cin >> choice;
}
