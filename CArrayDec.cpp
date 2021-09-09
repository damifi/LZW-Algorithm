///*
// * CArrayDec.cpp
// *
// *  Created on: 14.06.2014
// *      Author: Daniel Fischer
// */

#include "CArrayDec.hpp"
#include <vector>
#include <exception>
#include <iostream>

CArrayDec::CArrayDec()
{
	for(int i=0;i<256;i++)
	{
		m_symbolTable[i].setSymbol(intToString(i));
	}
}

int CArrayDec::searchInTable(const string &zei)
{
	int i =0;
	for(i=0; i<LZW_DICT_SIZE; i++)
	{
		if(m_symbolTable[i].getSymbol().compare(zei) == 0) {return i;}
	}
	return -1;
}

string CArrayDec::decode(const vector<unsigned int>& vec)
{
	std::string out, Sv, S;
	std::vector<unsigned int>::const_iterator pos;
	unsigned int freeDictPos = 256;
	if(vec.empty()) return "";			//wenn Eingabevektor leer ist, leeren string ausgeben
	pos = vec.begin();
	Sv = m_symbolTable[*pos].getSymbol();		//ersten index einlesen, zugehörigen string speichern
	out = Sv;
	for(pos = vec.begin()+1; pos !=vec.end(); ++pos)			// Durchläuft den rest vom vektor
	{
		if(*pos > freeDictPos-1 )							//falls Index aus dem Vektor noch nicht im Dictionary ist...
		{
			S = Sv + Sv[0];					//zuvor decodierten string um sein erstes zeichen verlängern
		}
		else								// ansonsten...
		{
			S = m_symbolTable[*pos].getSymbol();		//string mit dem indexwert aus dictionary auslesen
		}
		out = out + S;						//Resultat an den ausgabestring anhängen
		m_symbolTable[freeDictPos].setSymbol((Sv+S[0]));
		freeDictPos++;
		Sv = S;
		if(freeDictPos >= LZW_DICT_SIZE)					// Error
		{
			std::cerr << "ERROR: Kein Platz im Dictionary mehr vorhanden!";
			std::terminate();
		}
	}
	return out;
}
