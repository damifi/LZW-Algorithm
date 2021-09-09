/*
 * CEntry.h
 *
 *  Created on: 02.05.2014
 *      Author: Daniel Fischer
 */
#include <string>
#ifndef CENTRY_H_
#define CENTRY_H_

class CEntry
{
public:
	CEntry();
	~CEntry();
	const std::string& getSymbol() const;
	void setSymbol(std::string symbol);
	static unsigned int getNumber();
private:
	std::string m_symbol;
	static unsigned int m_number;
};



#endif /* CENTRY_H_ */
