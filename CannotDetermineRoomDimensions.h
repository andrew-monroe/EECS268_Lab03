/**
*	@file CannotDetermineRoomDimensions.h
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Header file for CannotDetermineRoomDimensions exception
*/

#ifndef CannotDetermineRoomDimensions_h
#define CannotDetermineRoomDimensions_h

#include <stdexcept>

class CannotDetermineRoomDimensions: public std::runtime_error
{
    public:
        CannotDetermineRoomDimensions(const char* msg);
};

#endif
