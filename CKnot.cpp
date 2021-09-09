/*
 * CKnot.cpp
 *
 *  Created on: 15.05.2014
 *      Author: Daniel Fischer
 */
#include "CKnot.hpp"

CKnot::CKnot():m_parent(-2){}
CKnot::~CKnot(){}

const int CKnot::getParent() const
{
	return m_parent;
}

void CKnot::setParent(int parent)
{
	m_parent = parent;
}



