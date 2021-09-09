/*
 * CArrayEnc.hpp
 *
 *  Created on: 14.06.2014
 *      Author: Daniel Fischer
 */


/*!
\file CArrayEnc.hpp
\brief Klasse CArrayEnc Abgeleitete Klasse für Enkodierung des LZW-Algorithmus als Array

Dieses File enthält die von CEnc abgeleitete Klasse CArrayEnc.

*/

#include "CEnc.hpp"
#include "CArray.hpp"
#include "CEntry.hpp"
#ifndef CARRAYENC_HPP_
#define CARRAYENC_HPP_

/*!
\class CArrayEnc
\brief Abgeleitete Klasse für den Encoder als Array

Abgeleitete Klasse für die Encoder als Array.
CArrayEnc erbt von CEnc.
Basisklasse der Encoderklassen CArrayDec und CTrieDec.
Von dieser Klasse CDec selbst können keine Instanzen erstellt werden,
sie ist abstrakt.
 */

class CArrayEnc : public CEnc
{
public:
	CArrayEnc();
	~CArrayEnc();
	int searchInTable(const string &zei);
	vector<unsigned int> encode(const string &zei);
private:
	CArray<CEntry, LZW_DICT_SIZE> m_symbolTable;
};



#endif /* CARRAYENC_HPP_ */
