#ifndef RECEIPTLINE_H

#define RECEIPTLINE_H

#define _CRT_SECURE_NO_WARNINGS

#include "Cont.h"
#include "Receipt.h"
#include "Product.h"
#include "date_time.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


class TReceiptLine {
private:
	int k;
	float sum;
	TProduct product;
public:
	TReceiptLine();

	TReceiptLine(const TProduct& _product);

	void AddProduct();

	void DeleteProduct();

	int GetK();

	float GetSum();

	string GetNamepr();


	void Print() ;

};

#endif 