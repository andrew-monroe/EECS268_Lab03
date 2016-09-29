

#include "MathTools.h"
#include "NegativeDiscriminant.h"
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"

int MathTools::intersectLineUnitCircle(double d, double e, double f, double** xy)
        throw (NoIntersection)
{
    int intersections = 0;

    try {
    intersections = solveQuadratic(d*d + e*e, e*f, f*f - d*d, xy[0]);
    }
    catch (NegativeDiscriminant& e)
    {
        throw(NoIntersection("ERROR: Line does not intersect with circle."));
    }

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

void MathTools::roomDimensions(double Area, double Extra, double minRequiredLength,
        double& width, double& length) throw (CannotDetermineRoomDimensions)
{
    double* possibleLengths = new double[2];

    try
    {
        if (solveQuadratic(1, Extra, -Area, possibleLengths) == 1)
        {
            if (possibleLengths[0] <= minRequiredLength)
            {
                throw(CannotDetermineRoomDimensions("ERROR: Cannot calculate valid room dimensions."));
            }
            else
            {
                length = possibleLengths[0];
            }
        }
        else
        {
            if (possibleLengths[0] <= minRequiredLength &&
                    possibleLengths[1] <= minRequiredLength)
            {
                throw(CannotDetermineRoomDimensions("ERROR: Cannot calculate valid room dimensions."));
            }
            else if (possibleLengths[0] < minRequiredLength)
            {
                length = possibleLengths[1];
            }
            else
            {
                length = possibleLengths[0];
            }
        }

        width = length + Extra;
    }
    catch(NegativeDiscriminant& e)
    {
        throw(CannotDetermineRoomDimensions("ERROR: Cannot calculate valid room dimensions."));
    }

    delete[] possibleLengths;
}

int MathTools::solveQuadratic(double a, double b, double c, double roots[])
        throw (NegativeDiscriminant)
{
    if (getDiscriminant(a, b, c) < 0)
        throw (NegativeDiscriminant("ERROR: Negative discriminant."));

    if (getDiscriminant(a, b, c) == 0)
    {
        roots[0] = -b / (2*a);

        return(1);
    }
    else
    {
        roots[0] = ((-b + sqrt(getDiscriminant(a, b, c))) / (2*a));
        roots[1] = ((-b - sqrt(getDiscriminant(a, b, c))) / (2*a));

        return(2);
    }
}

double MathTools::getDiscriminant(double a, double b, double c)
{
    return(b*b - 4*a*c);
}
