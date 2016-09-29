

#ifndef NoIntersection_h
#define NoIntersection_h

#include <stdexcept>

class NoIntersection: public std::runtime_error
{
    public:
        NoIntersection(const char* msg);
};

#endif
