

#ifndef "CannotDetermineRoomDimensions_h"
#define "CannotDetermineRoomDimensions_h"

#include <stdexcept>

class CannotDetermineRoomDimensions: public std::runtime_error
{
    public:
        CannotDetermineRoomDimensions(const char* msg);
};

#define
