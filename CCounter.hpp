/*
 * CCounter.cpp
 *
 *  Created on: 09.05.2014
 *      Author: Daniel Fischer
 */


#ifndef CCOUNTER_H_
#define CCOUNTER_H_

class CCounter
{
public:
	CCounter();
	virtual ~CCounter();
	virtual void count() = 0;
	int getValue();
	void setValue(int Value);
private:
	int m_value;
};
#endif /* CCOUNTER_H_ */
