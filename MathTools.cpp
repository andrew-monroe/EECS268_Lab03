

#include "MathTools.h"
#include "MathToolsInterface.h"

int intersectLineUnitCircle(double d, double e, double f, double xy[2][])
    throw (NoIntersection) = 0
{

}

void roomDimensions(double Area, double Extra, double minRequiredLength,
    double& width, double& length) throw (CannotDetermineRoomDimensions) = 0
{

}

int solveQuadratic(double a, double b, double c, double roots[])
    throw (NegativeDiscriminant) = 0
{

}
