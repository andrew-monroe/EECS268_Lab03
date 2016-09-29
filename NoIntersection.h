/**
*	@file NoIntersection.h
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Header file for NoIntersection exception
*/

#ifndef NoIntersection_h
#define NoIntersection_h

#include <stdexcept>

class NoIntersection: public std::runtime_error
{
    public:
        NoIntersection(const char* msg);
};

#endif
