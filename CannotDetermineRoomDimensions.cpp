

#include "CannotDetermineRoomDimensions.h"

CannotDetermineRoomDimensions::CannotDetermineRoomDimensions(const char* msg):
    std::runtime_error(msg)
{
    
}
