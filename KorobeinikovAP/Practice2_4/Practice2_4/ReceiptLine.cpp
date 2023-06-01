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




TReceiptLine:: TReceiptLine() {
	k = 0;
	sum = 0.f;
}

TReceiptLine:: TReceiptLine(const TProduct& _product) {
	k = 1;
	sum = _product.GetCost();
	product = _product;
}

void TReceiptLine:: AddProduct() {
	k += 1;
	sum += product.GetCost();
}

void TReceiptLine:: DeleteProduct() {
	k -= 1;
	sum -= product.GetCost();
}

int TReceiptLine:: GetK() {
	return k;
}

float TReceiptLine:: GetSum() {
	return sum;
}

string TReceiptLine:: GetNamepr() {
	return product.GetName();
}


void TReceiptLine:: Print() {
	cout << setw(15) << left << GetNamepr()
		<< setw(10) << k
		<< setw(10) << fixed;
	cout.precision(2);
	cout << sum
		<< endl;
}

};
