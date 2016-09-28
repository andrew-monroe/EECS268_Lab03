

#include "MathTools.h"
#include "MathToolsInterface.h"

int MathTools::intersectLineUnitCircle(double d, double e, double f, double xy[2][])
    throw (NoIntersection)
{

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
        if (getDiscriminant() < 0)
            throw (NegativeDiscriminant e);

        if (getDiscriminant() == 0)
        {
            roots[0] = -b / (2*a);

            return(1);
        }
        else
        {
            roots[0] = ((-b + math.sqrt(getDiscriminant())) / (2*a));
            roots[1] = ((-b - math.sqrt(getDiscriminant())) / (2*a));

            return(2);
        }
    }
    catch (NegativeDiscriminant& e)
    {

    }
}

double MathTools::getDiscriminant(double a, double b, double c)
{
    return(b*b - 4*a*c);
}
