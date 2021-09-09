/*
 * CCounter.cpp
 *
 *  Created on: 06.04.2014
 *      Author: Daniel Fischer
 */
#include "CCounter.hpp"

CCounter::CCounter():m_value(0){}

CCounter::~CCounter(){}

void CCounter::count(){}

int CCounter::getValue()
{
	return m_value;
}

void CCounter::setValue(int value)
{
	m_value = value;
}
