/*
 * CEntry.cpp
 *
 *  Created on: 02.05.2014
 *      Author: Daniel Fischer
 */
#include "CEntry.hpp"
#include <string>

unsigned int CEntry::m_number = 0;

CEntry::CEntry():m_symbol("")
{
	m_number++;
}
CEntry::~CEntry()
{
	m_number--;
}

const std::string& CEntry::getSymbol() const
{
	return m_symbol;
}

void CEntry::setSymbol(std::string symbol)
{
	m_symbol = symbol;
}

unsigned int CEntry::getNumber()
{
	return m_number;
}
