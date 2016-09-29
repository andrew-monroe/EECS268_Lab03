/**
*	@file Executive.h
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Header file for Executive class. Contains the code for all
        user input and system output. Creates MathTools class variable to use
        MathTools methods.
*/

#ifndef Executive_h
#define Executive_h

class Executive
{
    public:
        /*
            Runs the program. Calls menu method to get user decision on what to do.
            Calls appropriate method based on user's decision. Handles the possible
            exceptions. Loops until user quits.
        */
        void run();

    private:
        /*
            Prints out the menu of options for the user. Returns the user's choice.
        */
        int menu();

        /*
            Gathers user input to solve for the roots in a quadratic equation. Calls
            MathTools method to solve the eqaution with the user's values. Outputs the
            results.
        */
        void quadraticSolver();

        /*
            Gathers user input to solve for the intersection of a line with a unit
            circle. Calls MathTools method to find the intersection(s) using the user's
            values. Outputs the results.
        */
        void intersectFinder();

        /*
            Gather user input to find dimensions of a room of certain area with
            width being some user-specified amount greater than length. Calls MathTools
            method to perform calculations. Displays results.
        */
        void roomSizeFinder();
};

#endif
