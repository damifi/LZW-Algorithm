/*
 * XOutOfBounds.h
 *
 *  Created on: 16.05.2014
 *      Author: Daniel Fischer
 */
#include <string>
#include <exception>
#ifndef XOUTOFBOUNDS_H_
#define XOUTOFBOUNDS_H_

class XOutOfBounds : public std::exception
{
private :
	std::string m_msg;
public :
	XOutOfBounds(const char* msg);
	virtual ~XOutOfBounds() throw();
	const char* what() const throw();
};



#endif /* XOUTOFBOUNDS_H_ */
