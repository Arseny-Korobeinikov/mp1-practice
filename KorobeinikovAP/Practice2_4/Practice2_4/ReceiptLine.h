#ifndef RECEIPTLINE_H
#define RECEIPTLINE_H


#include "Cont.h"
#include "Receipt.h"
#include "Product.h"
#include"Work.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


class TReceiptLine {
private:
	int k;
	int sum;
	TProduct product;
public:
	TReceiptLine() {
		k = 0;
		sum = 0;
	}

	TReceiptLine(TProduct _product) {
		k = 1;
		sum = product.GetCost();
		product = _product;
	}

	void AddProduct() {
		k += 1;
		sum += product.GetCost();
	}

	void DeleteProduct() {
		k -= 1;
		sum  -= product.GetCost();
	}

	int GetK() {
		return k;
	}

	string GetNamepr() {
		return product.GetName();
	 }



};

#endif 