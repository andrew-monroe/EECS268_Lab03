

#ifndef MathTools_h
#define MathTools_h

#include <stdexcept>
#include <math.h>
#include "MathToolsInterface.h"

class MathTools: public MathToolsInterface
{
    public:
        int intersectLineUnitCircle(double d, double e, double f, double** xy)
    		throw (NoIntersection);

        void roomDimensions(double Area, double Extra, double minRequiredLength,
        	double& width, double& length) throw (CannotDetermineRoomDimensions);

        int solveQuadratic(double a, double b, double c, double roots[])
			throw (NegativeDiscriminant);

    private:
        double getDiscriminant(double a, double b, double c);
};

#endif
