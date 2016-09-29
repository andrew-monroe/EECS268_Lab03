/**
*	@file NegativeDiscriminant.h
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Header file for NegativeDiscriminant exception
*/

#ifndef NegativeDiscriminant_h
#define NegativeDiscriminant_h

#include <stdexcept>

class NegativeDiscriminant: public std::runtime_error
{
    public:
        NegativeDiscriminant(const char* msg);
};

#endif
