/*
 * CTrieEnc.cpp
 *
 *  Created on: 19.06.2014
 *      Author: Daniel Fischer
 */

#include "CTrieEnc.hpp"
#include "CForwardCounter.hpp"
#include <string>
#include "CLZW.hpp"
#include "CDoubleHashing.hpp"
#include "CArray.hpp"

CTrieEnc::CTrieEnc():m_symbolTable()
{
	for(int i=0; i<256; i++)
	{
		m_symbolTable[i].setParent(-1);
		m_symbolTable[i].setSymbol(intToString(i));
	}
}

CTrieEnc::~CTrieEnc(){}

vector<unsigned int> CTrieEnc::encode(const string &in)
{
	unsigned int I, J, hashposition, hashposition_old;
	CDoubleHashing &hashing = CDoubleHashing::getInstance();
	CForwardCounter attemptCounter;
	std::string::const_iterator pos;
	vector<unsigned int> vec;
	if(in.empty())
	{
		return vec;
	}

	I = charToInt(in.at(0));

	for(pos = in.begin()+1; pos != in.end(); ++pos)
	{
		J = charToInt(*pos);
		attemptCounter.setValue(0);
		hashposition = hashing.hash(I, J, LZW_DICT_SIZE, attemptCounter.getValue());
		hashposition_old = hashposition;

		while((m_symbolTable[hashposition].getParent() != -2) && ((m_symbolTable[hashposition].getParent() != I) || (charToInt(m_symbolTable[hashposition].getSymbol().at(0)) != J)))
		{
			attemptCounter.count();
			hashposition = hashing.hash(I, J, LZW_DICT_SIZE, attemptCounter.getValue());

			if(hashposition == hashposition_old)
			{
				break;
			}
		}

		if(m_symbolTable[hashposition].getParent() == I && m_symbolTable[hashposition].getSymbol() == intToString(J))
				{
					I = hashposition;
		//			++pos;
		//			J = charToInt(*pos);
				}

		if(m_symbolTable[hashposition].getParent() == -2)
		{
			m_symbolTable[hashposition].setParent(I);
			m_symbolTable[hashposition].setSymbol(intToString(J));
			vec.push_back(I);
			I = J;
//			++pos;
//			J = charToInt(*pos);
		}


	}
	vec.push_back(I);
	return vec;
}
