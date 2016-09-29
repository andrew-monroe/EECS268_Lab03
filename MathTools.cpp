/**
*	@file MathTools.cpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Implementation for MathTools class derived from MathToolsInterface
        base class. Has three methods, one to find quadratic formula roots,
        another to find where a given line intersects a circle, and one to
        determine dimensions for a room given area and difference between
        length and width.
*/

#include "MathTools.h"
#include "NegativeDiscriminant.h"
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"

/*
    Finds the intersection of a line dx + ey + f = 0 with the unit circle.
    Returns number of intersections. Can throw exception if there are no
    intersections.
*/
int MathTools::intersectLineUnitCircle(double d, double e, double f, double** xy)
        throw (NoIntersection)
{
    //create and intialize intersections variable
    int intersections = 0;

    //try solving quadratic equation for intersection points
    //if NegativeDiscriminant exception is thrown, it will be caught and a
    //  NoIntersection exception will be thrown
    try {
        intersections = solveQuadratic(d*d + e*e, e*f, f*f - d*d, xy[0]);
    }
    catch (NegativeDiscriminant& e)
    {
        throw(NoIntersection("ERROR: Line does not intersect with circle."));
    }

    //finds x values for intercept points and stores them
    //returns number of intersections
    if(intersections == 1)
    {
        xy[1][0] = (-f - e*xy[0][0]) / d;

        return(1);
    }
    else
    {
        xy[1][0] = (-f - e*xy[0][0]) / d;

        xy[1][1] = (-f - e*xy[0][1]) / d;

        return(2);
    }
}

/*
    Finds the dimensions of a room based on user-specified area of the room,
    difference between length and width of the room, and minimum length of the
    room. Will throw an exception if the user-specified values do not allow for
    a valid room.
*/
void MathTools::roomDimensions(double Area, double Extra, double minRequiredLength,
        double& width, double& length) throw (CannotDetermineRoomDimensions)
{
    //create a small double array to store possible lengths
    double* possibleLengths = new double[2];

    //try to calculate the dimensions for the room by using the quadratic
    //  formula
    //will catch NegativeDiscriminant exception and throw
    //  CannotDetermineRoomDimensions exception if room dimensions cannot be
    // found
    try
    {
        //if only one possible length is returned
        if (solveQuadratic(1, Extra, -Area, possibleLengths) == 1)
        {
            //throws exception if possible length isn't longer than user's
            //  minimum length
            if (possibleLengths[0] <= minRequiredLength)
            {
                throw(CannotDetermineRoomDimensions("ERROR: Cannot calculate valid room dimensions."));
            }
            else
            {
                length = possibleLengths[0];
            }
        }
        else //if two possible lengths are returned
        {
            //throws exception if neither possible length is longer than user's
            //  minimum length
            if (possibleLengths[0] <= minRequiredLength &&
                    possibleLengths[1] <= minRequiredLength)
            {
                throw(CannotDetermineRoomDimensions("ERROR: Cannot calculate valid room dimensions."));
            }
            else if (possibleLengths[0] < minRequiredLength)
            {
                //for when first possible length is too short
                length = possibleLengths[1];
            }
            else
            {
                //otherwise just use first possible length
                length = possibleLengths[0];
            }
        }

        //define value for width
        width = length + Extra;
    }
    catch(NegativeDiscriminant& e)
    {
        throw(CannotDetermineRoomDimensions("ERROR: Cannot calculate valid room dimensions."));
    }

    //delete array
    delete[] possibleLengths;
}

/*
    Solves quadratic formula for given set of values.
    Can throw an exception if discriminant is negative.
    Returns number of roots.
*/
int MathTools::solveQuadratic(double a, double b, double c, double roots[])
        throw (NegativeDiscriminant)
{
    //throws NegativeDiscriminant exception if discriminant is negative
    if (getDiscriminant(a, b, c) < 0)
        throw (NegativeDiscriminant("ERROR: Negative discriminant."));

    //determines root when only one root exists (when determinant is zero)
    if (getDiscriminant(a, b, c) == 0)
    {
        roots[0] = -b / (2*a);

        return(1);
    }
    else //determines the two roots when there are two
    {
        roots[0] = ((-b + sqrt(getDiscriminant(a, b, c))) / (2*a));
        roots[1] = ((-b - sqrt(getDiscriminant(a, b, c))) / (2*a));

        return(2);
    }
}

/*
    Finds and returns the discriminant for a quadratic equation.
*/
double MathTools::getDiscriminant(double a, double b, double c)
{
    return(b*b - 4*a*c);
}
