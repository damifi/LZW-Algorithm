/*
 * CArray.h
 *
 *  Created on: 15.05.2014
 *      Author: Daniel Fischer
 */

#include "XOutOfBounds.hpp"
#ifndef CARRAY_H_
#define CARRAY_H_

template <typename T, unsigned int N> class CArray
{
	private:
		T *entries;
	public:
		T& operator[](unsigned int index);
		CArray();
		virtual ~CArray();
		CArray(CArray & other);
};


template<typename T, unsigned int N>
	CArray<T, N>::CArray():entries(new T[N]) {}


template<typename T, unsigned int N>
	CArray<T, N>::CArray(CArray & other)
	{
		entries = new T[N];
		for(int i=0; i<N; i++)
		{
			entries[i] = other.entries[i];
		}
	}


template<typename T, unsigned int N>
	T& CArray<T, N>::operator[](unsigned int index)
	{
		if(index >= N)
		{
			throw XOutOfBounds("Der Teil vom Array existiert nicht!");
		}
		return *(entries + index);
	}

template<typename T, unsigned int N>
	CArray<T, N>::~CArray()
	{
		delete[] entries;
	}





#endif /* CARRAY_H_ */

