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
	TProduct();
	TProduct(string code, string name, float cost);
	TProduct(const TProduct& pr);
	float GetCost() const;
	string GetName() const;
	string GetCode() const;
	TProduct operator=(const TProduct& pr);	
};

#endif 
