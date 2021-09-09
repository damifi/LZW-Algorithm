/*
 * XOutOfBounds.cpp
 *
 *  Created on: 16.05.2014
 *      Author: Daniel Fischer
 */
#include "XOutOfBounds.hpp"



XOutOfBounds::XOutOfBounds(const char* msg):exception(), m_msg(msg){}

XOutOfBounds::~XOutOfBounds() throw() {}

const char* XOutOfBounds::what() const throw()
{
	return m_msg.c_str();
}
