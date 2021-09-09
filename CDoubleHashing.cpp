/*
 * CDoubleHashing.cpp
 *
 *  Created on: 22.05.2014
 *      Author: Daniel Fischer
 */


#include "CDoubleHashing.hpp"

CDoubleHashing::CDoubleHashing(){}
CDoubleHashing::CDoubleHashing(const CDoubleHashing& other){}
//CDoubleHashing CDoubleHashing::operator=(CDoubleHashing& other){}  braucht man anscheinend nicht, ansonsten mal mit rückgabetyp viod probieren

CDoubleHashing CDoubleHashing::m_instance;


CDoubleHashing& CDoubleHashing::getInstance()
{
return m_instance;
}

unsigned int CDoubleHashing::hash(unsigned int I, unsigned int J,  unsigned int dict_size, unsigned int attempt)
{
unsigned int x = (I+J)*(I+J+1)/2+J;
return (x + attempt * (1 + (x % (dict_size-2))) ) % dict_size;
}
