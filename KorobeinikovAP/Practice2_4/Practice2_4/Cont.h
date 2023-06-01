#ifndef CONT_H
#define CONT_H

#define _CRT_SECURE_NO_WARNINGS

#include "Receipt.h"
#include "Product.h"
#include "ReceiptLine.h"
#include "date_time.h"
#include <string>
#include <iostream>

using namespace std;


template <typename T>
class TCont {
private:
	int size;
	T* el;
	int step;
	int pos;
public:
	TCont() {
		size = 1;
		step = 1;
		pos = 0;
		el = new T[size];
	}

	TCont(int size, int step) {
		this->step = step;
		this->size = size;
		pos = 0;
		el = new T[size];
	}

	TCont(const TCont& Container) {
		size = Container.size;
		el = new T[size];
		for (int i = 0; i < size; i++) {
			el[i] = Container.el[i];
		}
		step = Container.step;
		pos = Container.pos;
	}

	~TCont() {
		delete []el;
	}

	T& operator [] (int index) const{
		return (el[index]);
	}


	TCont operator=(const TCont& _cnt) {	
		if (this != &_cnt) {
			delete[] el;;
			size = _cnt.size;
			pos = _cnt.pos;
			el = new T[size];
			for (int i = 0; i < pos; i++)
				el[i] = _cnt.el[i];
		}
		return *this;
	}




	int GetSize() {
		return size;
	}

	void Insert(const T& obj) {
		if (pos+1 == size) {
			resize();
			pos++;
			el[pos] = obj;
			return;
		}
		pos++;
		el[pos] = obj;
		return;
	}

	void Del(int index) {
		for (int i = index; i < size; i++) {
			el[i] = el[i + 1];
		}
		pos--;
	}

	void resize() {
		T* tmp = new T[size];
		for (int i = 0; i < size; i++) {
			tmp[i] = el[i];
		}
		size += step;
		el = new T[size];
		for (int i = 0; i < size - step; i++) {
			el[i] = tmp[i];
		}
	}


};


#endif 
