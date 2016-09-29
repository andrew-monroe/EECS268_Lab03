

#include "MathTools.h"
#include "NegativeDiscriminant.h"
#include "NoIntersection.h"
#include "CannotDetermineRoomDimensions.h"

int MathTools::intersectLineUnitCircle(double d, double e, double f, double** xy)
    throw (NoIntersection)
{
    try
    {
        switch (solveQuadratic(d*d + e*e, e*f, f*f - d*d, xy[0]))
        {
            case 0:
                throw (NoIntersection("No intersection here."));
                break;
            case 1:
                xy[1][0] = (-f - e*xy[0][0]) / d;

                return(1);
                break;
            case 2:
                xy[1][0] = (-f - e*xy[0][0]) / d;

                xy[1][1] = (-f - e*xy[0][1]) / d;

                return(2);
                break;
        }
    }
    catch(NoIntersection& e)
    {
        return(0);
    }
}

void MathTools::roomDimensions(double Area, double Extra, double minRequiredLength,
    double& width, double& length) throw (CannotDetermineRoomDimensions)
{

}

int MathTools::solveQuadratic(double a, double b, double c, double roots[])
    throw (NegativeDiscriminant)
{
    try
    {
        if (getDiscriminant(a, b, c) < 0)
            throw (NegativeDiscriminant("Negative discriminant foud."));

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
    catch (NegativeDiscriminant& e)
    {
        return(0);
    }
}

double MathTools::getDiscriminant(double a, double b, double c)
{
    return(b*b - 4*a*c);
}
