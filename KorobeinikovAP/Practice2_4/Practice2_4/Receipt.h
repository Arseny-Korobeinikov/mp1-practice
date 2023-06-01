#ifndef RECEIPT_H
#define RECEIPT_H

#define _CRT_SECURE_NO_WARNINGS

#include "Cont.h"
#include "Product.h"
#include "ReceiptLine.h"
#include "date_time.h"
#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;



class TReceipt {
private:
	long index;
	TDate date;
	TTime time_;
	TCont <TReceiptLine> lines;
public:
	TReceipt();
	~TReceipt();
	void AddProduct(TProduct product);
	void DeleteProduct(TProduct product);
	int GetIndex();
	float Total();
	void output();
};


TCont<TProduct> ReadFileBase(const string& file_path);

TProduct ReadProductEntity(ifstream& file);


TProduct ScanProduct(TCont<TProduct> Base);

TCont<TReceipt> f_work(TCont<TProduct> Base);


#endif 

