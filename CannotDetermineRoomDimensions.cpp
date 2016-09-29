/**
*	@file CannotDetermineRoomDimensions.cpp
*	@author Andy Monroe
*	@date 09-29-2016
*	@brief Implementation file for CannotDetermineRoomDimensions exception
*/

#include "CannotDetermineRoomDimensions.h"

CannotDetermineRoomDimensions::CannotDetermineRoomDimensions(const char* msg):
    std::runtime_error(msg)
{

}
