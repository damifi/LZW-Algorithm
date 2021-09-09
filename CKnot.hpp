/*
 * CKnot.h
 *
 *  Created on: 15.05.2014
 *      Author: Daniel Fischer
 */
#include "CEntry.hpp"
#ifndef CKNOT_H_
#define CKNOT_H_

class CKnot : public CEntry
{
private :
	int m_parent;

public :
	const int getParent() const;
	void setParent(int parent);
	CKnot();
	~CKnot();
};



#endif /* CKNOT_H_ */
