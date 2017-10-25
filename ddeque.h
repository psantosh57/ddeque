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

	ddeque_iterator(T* x = 0) : _current(x) {

		cout << "In ddeque_iterator const" << endl;
	}

	~ddeque_iterator() {

		cout << "In ddeque_iterator dest" << endl;
	}

	const T& operator*() const {

		return *(_current);
	}

	ddeque_iterator& operator++() {

		++_current;

		return *this;
	}

	ddeque_iterator& operator--() {

		--_current;

		return *this;
	}

	bool operator!=(const ddeque_iterator& rhs) {

		return (_current != rhs._current);
	}

private:

	T* _current;
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

	ddeque() : _dequeBack(), _dequeFront(), _ptr(0), _front(0), _back(0) {

		cout << "In ddqeue const" << endl;

	}

	~ddeque() {

		cout << "In ddeque dest" << endl;
	}

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

		return ddeque<T>::iterator(&front());
	}

	iterator end() {

		return ddeque<T>::iterator(&back());
	}
	void push_back(const T& t);
	void push_front(const T& t);
	T& front();
	T& back();
	int size();
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

