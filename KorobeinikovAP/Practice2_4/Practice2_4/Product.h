#ifndef PRODUCT_H 
#define PRODUCT_H 

#define _CRT_SECURE_NO_WARNINGS

#include "Cont.h"
#include "Receipt.h"
#include "ReceiptLine.h"
#include "date_time.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class TProduct {
private:
	string code;
	string name;
	float cost;
public:
	TProduct() {}

	TProduct(string code, string name, float cost) {
		this->code = code;
		this->cost = cost;
		this->name = name;
	}

	TProduct(const TProduct& pr) {
		code = pr.code;
		name = pr.code;
		cost = pr.cost;
	}

	float GetCost() const{
		return cost;
	}

	string GetName() const{
		return name;
	}

	string GetCode() const{
		return code;
	}

	TProduct operator=(const TProduct& pr) {
		code = pr.code;
		name = pr.code;
		cost = pr.cost;
		return (*this);
	}


	
};

#endif 
