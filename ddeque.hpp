/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ddeque.hpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

#include "ddeque.h"

/*----------------------------------------------------------------
Write all code here
-----------------------------------------------------------------*/
template <typename T>
void ddeque<T>::push_back(const T& t) {

	_deque[_ptr++] = t;

}


template <typename T>
int ddeque<T>::size() {

	return _ptr;
}










//EOF


