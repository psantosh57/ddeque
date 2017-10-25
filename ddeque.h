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

private:

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

	ddeque() : _dequeBack(), _dequeFront(), _ptr(0), _front(-1), _back(-1) {

		cout << "In ddqeue const" << endl;

	}

	~ddeque() {

		cout << "In ddeque dest" << endl;
	}

	T& operator[] (int index) {

		if (_front == -1) {

			return _dequeBack[index];
		}
		else if (_back == -1) {

			return _dequeFront[index];
		}
		//return _dequeBack[index];
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

