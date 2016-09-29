

#ifndef "NegativeDiscriminant_h"
#define "NegativeDiscriminant_h"

#include <stdexcept>

class NegativeDiscriminant: public std::runtime_error
{
    public:
        NegativeDiscriminant(const char* msg);
};

#define
