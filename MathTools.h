/**
*	@file MathTools.h
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Header for MathTools class derived from MathToolsInterface
        base class. Has three methods, one to find quadratic formula roots,
        another to find where a given line intersects a circle, and one to
        determine dimensions for a room given area and difference between
        length and width.
*/

#ifndef MathTools_h
#define MathTools_h

#include <stdexcept>
#include <math.h>
#include "MathToolsInterface.h"

class MathTools: public MathToolsInterface
{
    public:
        /*
            Finds the intersection of a line dx + ey + f = 0 with the unit circle.
            Returns number of intersections. Can throw exception if there are no
            intersections.
        */
        int intersectLineUnitCircle(double d, double e, double f, double** xy)
    		throw (NoIntersection);

        /*
            Finds the dimensions of a room based on user-specified area of the room,
            difference between length and width of the room, and minimum length of the
            room. Will throw an exception if the user-specified values do not allow for
            a valid room.
        */
        void roomDimensions(double Area, double Extra, double minRequiredLength,
        	double& width, double& length) throw (CannotDetermineRoomDimensions);

        /*
            Solves quadratic formula for given set of values.
            Can throw an exception if discriminant is negative.
            Returns number of roots.
        */
        int solveQuadratic(double a, double b, double c, double roots[])
			throw (NegativeDiscriminant);

    private:
        /*
            Finds and returns the discriminant for a quadratic equation.
        */
        double getDiscriminant(double a, double b, double c);
};

#endif
