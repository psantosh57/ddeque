#pragma once
/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ddeque.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ddeque class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ddeque_H
#define ddeque_H

#include "../util/util.h"
#include "../darray/darray.h"

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
template <typename T>
class ddeque;

template <typename T>
class ddeque_iterator;

/*--------------------------------------------------------
typename ddeque iterator
----------------------------------------------------------*/
template <typename T>
class ddeque_iterator {
public:
	//WRITE CODE

	ddeque_iterator(T* x = 0, T* y = 0, int front = 0, int back = 0) : _current(x), _currFront(x), _currBack(y), _itrFront(front), _itrBack(back) {}

	~ddeque_iterator() {
		_current = 0;
	}

	T& operator*() const {

		return *(_current);
	}

	ddeque_iterator& operator++() {

		if ((_itrFront-1) > 0) {

			--_current;
			//_current = --_currFront;
			--_itrFront;

		}
		else {

			_current = _currBack++;

		}
		

		return *this;
	}

	ddeque_iterator& operator--() {

		if ((_itrBack - 1) >= 0 && _currBack) {

			--_current;
			//_current = --_currBack;
			--_itrBack;

		}
		else {

			_current = _currBack++;

		}

		return *this;
	}

	bool operator!=(const ddeque_iterator& rhs) {

		return (_current != rhs._current);
	}

private:

	T* _current;
	T* _currFront;
	T* _currBack;
	int _itrFront;
	int _itrBack;
	//WRITE CODE
};

/*--------------------------------------------------------
class ddeque
----------------------------------------------------------*/
template <typename T>
class ddeque {
public:
	/* WRITE ALL PUBLIC FUNCTION HERE */
	/* CANNOT HAVE ANY PUBLIC DATA HERE */
	typedef ddeque_iterator<T> iterator;

	//size(), push_front() push_back() pop_front() pop_back() front() back() a[i]
	//All the above functions must have O(1) time complexity
	//No credit will be given if takes O(n)
	//Write CODE here

	ddeque() : _dequeBack(), _dequeFront(), _ptr(0), _front(0), _back(0) {}

	~ddeque() {}

	T& operator[] (int index) {

		if ((_front - index) > 0) {

			return _dequeFront[(_front - index - 1)];
		}
		else if (_front == index) {

			return _dequeBack[0];
		}
		else {

			return _dequeBack[(index - _front)];
		}
	}

	iterator begin() {

		return ddeque<T>::iterator(&front(), &_dequeBack[0], _front, _back);
	}

	iterator end() {

		if (_back == 0) {

			return ddeque<T>::iterator(&_dequeFront[0], 0, _front, _back);
		}
		else {

			//return _dequeBack[_back];
			return ddeque<T>::iterator(&_dequeBack[_back], &_dequeFront[0], _front, _back);
		}

		
	}
	void push_back(const T& t);
	void push_front(const T& t);
	void pop_back();
	void pop_front();
	T& front();
	T& back();
	int size();
	bool empty();
	bool display() const { return _display; }
	void set_display(bool x) {
		darray<T>::set_display(x);
		_display = x;
	}

private:
	/* MUST USE only darray<T>. You can use multiples of darray<T> */
	/* Can have some private variables */
	/* Write Code here */

	darray<T> _dequeBack;
	darray<T> _dequeFront;
	int _ptr;
	int _front;
	int _back;


	/* CAN HAVE ANY PRIVATE FUNCION */
	void _put(int pos, const T& a);
};

#include "ddeque.hpp"

#endif
//EOF

