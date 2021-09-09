/*
 * CArrayEnc.cpp
 *
 *  Created on: 14.06.2014
 *      Author: Daniel Fischer
 */
#include <string>
#include <vector>
#include "CArrayEnc.hpp"
#include <iostream>

CArrayEnc::CArrayEnc()
{
	for(int i=0;i<256;i++)
	{
		m_symbolTable[i].setSymbol(intToString(i));
	}
}

CArrayEnc::~CArrayEnc(){}

int CArrayEnc::searchInTable(const string &zei)
{
	int i =0;
	for(i=0; i<LZW_DICT_SIZE; i++)
	{
		if(m_symbolTable[i].getSymbol().compare(zei) == 0) {return i;}
	}
	return -1;
}

vector<unsigned int> CArrayEnc::encode(const string &zei)
{
	std::string S ="";
	std::string Sx;
	char x;
	std::vector<unsigned int> vec;
	unsigned int freeDictPos = 256;
	if(zei.compare("") == 0) 					// wenn der string leer ist terminieren
		{
			return vec;
		}
	std::string::const_iterator pos;

	for(pos = zei.begin(); pos != zei.end(); ++pos)  //zeichenweise Einlesen
	{
		x = *pos;                               	// Zeichen einlesen
		Sx = S + x;										// String S mit Zeichen x zusammenfügen
		if(searchInTable(Sx) != -1)						// prüfen ob Sx bereits im Dictionary ist
		{
			S = Sx;										// Wenn ja, Sx an S zuweisen
		}
		else											// Wenn nein...
		{
			vec.push_back(searchInTable(S));			//Index der Zeichenkette dem Ausgabevektor hinzufügen
			m_symbolTable[freeDictPos].setSymbol(Sx);				// Sx wird an der ersten freien Stelle im Dict hinzugefügt
			freeDictPos++;
			S=x;										//S bekommt zuletzt eingelesenes Zeichen x zugewiesen.
		}
	}
	vec.push_back(searchInTable(S));					// Position der letzten Zeichenkette in den Ausgabevektor schreiben.
	return vec;
}
