#ifndef CONT_H
#define CONT_H


#include "Receipt.h"
#include "Product.h"
#include"Work.h"
#include "ReceiptLine.h"
#include <string>
#include <fstream>
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
		pos = size;
	}

	~TCont() {
		free[] el;
	}

	T& operator [] (int index) const{
		return (el[index]);
	}

	int GetSize() {
		return size;
	}

	void Insert(const T& obj) {
		if (pos == size) {
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
