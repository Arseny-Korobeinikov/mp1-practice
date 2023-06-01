#define _CRT_SECURE_NO_WARNINGS

#include "Cont.h"
#include "Receipt.h"
#include "Product.h"
#include "ReceiptLine.h"
#include <string>
#include <fstream>
#include <iostream>
#include<time.h>
#include <iomanip>

using namespace std;



TProduct::TProduct() {}

TProduct::TProduct(string code, string name, float cost) {
	this->code = code;
	this->cost = cost;
	this->name = name;
}

TProduct::TProduct(const TProduct& pr) {
	code = pr.code;
	name = pr.code;
	cost = pr.cost;
}

float TProduct::GetCost() const {
	return cost;
}

string TProduct::GetName() const {
	return name;
}

string TProduct::GetCode() const {
	return code;
}

TProduct TProduct::operator=(const TProduct& pr) {
	code = pr.code;
	name = pr.code;
	cost = pr.cost;
	return (*this);
}