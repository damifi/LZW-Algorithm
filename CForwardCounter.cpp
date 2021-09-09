/*
 * CForwardCounter.cpp
 *
 *  Created on: 11.04.2014
 *      Author: Daniel Fischer
 */
#include "CForwardCounter.hpp"

void CForwardCounter::count()
{
	int a = CCounter::getValue();
	a++;
	CCounter::setValue(a);
}



