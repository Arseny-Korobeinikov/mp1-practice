#ifndef PRODUCT_H 
#define PRODUCT_H 


#include "Cont.h"
#include "Receipt.h"
#include"Work.h"
#include "ReceiptLine.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class TProduct {
private:
	string code;
	string name;
	int cost;
public:
	TProduct() {};
	TProduct(string code, string name, int cost) {
		this->code = code;
		this->cost = cost;
		this->name = name;
	}
	TProduct(const TProduct& pr) {
		code = pr.code;
		name = pr.code;
		cost = pr.cost;
	}
	int GetCost() {
		return cost;
	}
	string GetName() {
		return name;
	}
	string GetCode() {
		return code;
	}
};






#endif 
