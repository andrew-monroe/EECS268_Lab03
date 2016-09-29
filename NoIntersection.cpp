/**
*	@file NoIntersection.cpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Implementation file for NoIntersection exception
*/

#include "NoIntersection.h"

NoIntersection::NoIntersection(const char* msg):
    std::runtime_error(msg)
{

}
