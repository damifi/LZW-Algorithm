/*
 * CArrayDec.hpp
 *
 *  Created on: 14.06.2014
 *      Author: Daniel Fischer
 */

/*!
\file CArrayDec.hpp
\brief Klasse CArrayDec abgeleitete Klasse für Decodierung des LZW-Algorithmus als Array

Dieses File enthält die von CDec abgeleite Klasse CArrayDec.
*/

#include "CDec.hpp"
#include "CArray.hpp"
#include "CEntry.hpp"
#ifndef CARRAYDEC_HPP_
#define CARRAYDEC_HPP_

class CArrayDec : public CDec
{
public:
	string decode(const vector<unsigned int>&);
	int searchInTable(const string &);
	CArrayDec();
private:
	CArray<CEntry, LZW_DICT_SIZE> m_symbolTable;
};



#endif /* CARRAYDEC_HPP_ */
