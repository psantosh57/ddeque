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

	_dequeBack[_back++] = t;
	_ptr++;

}

template <typename T>
void ddeque<T>::push_front(const T& t) {

	_dequeFront[_front++] = t;
	_ptr++;

}


template <typename T>
int ddeque<T>::size() {

	return _ptr;
}

template <typename T>
T& ddeque<T>::front() {

	if (_front == 0) {

		return _dequeBack[0];
	}
	else {

		return _dequeFront[(_front - 1)];
	}

}

template <typename T>
T& ddeque<T>::back() {

	if (_back == 0) {

		return _dequeFront[0];
	}
	else {

		return _dequeBack[(_back - 1)];
	}

}

template <typename T>
bool ddeque<T>::empty() {

	return (!_ptr);

}

template <typename T>
void ddeque<T>::pop_back() {

	if (empty()) {

		assert(0);
	}

	--_ptr;
	--_back;

}

template <typename T>
void ddeque<T>::pop_front() {

	if (empty()) {

		assert(0);
	}

	--_ptr;
	--_front;

}



//EOF


