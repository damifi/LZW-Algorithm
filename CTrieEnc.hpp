/*
 * CTrieEnc.hpp
 *
 *  Created on: 19.06.2014
 *      Author: Daniel Fischer
 */
#include "CKnot.hpp"
#include "CEnc.hpp"
#include "CLZW.hpp"
#include "CArray.hpp"
#include "CDoubleHashing.hpp"

#ifndef CTRIEENC_HPP_
#define CTRIEENC_HPP_

class CTrieEnc : public CEnc
{
public:
	CTrieEnc();
	virtual ~CTrieEnc();
	vector<unsigned int> encode(const string &in);
private:
	CArray<CKnot, LZW_DICT_SIZE> m_symbolTable;

};




#endif /* CTRIEENC_HPP_ */
