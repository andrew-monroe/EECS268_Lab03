/**
*	@file NegativeDiscriminant.cpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Implementation file for NegativeDiscriminant exception
*/

#include "NegativeDiscriminant.h"

NegativeDiscriminant::NegativeDiscriminant(const char* msg):
    std::runtime_error(msg)
{

}
