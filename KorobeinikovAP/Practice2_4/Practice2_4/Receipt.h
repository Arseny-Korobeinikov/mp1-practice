#ifndef RECEIPT_H
#define RECEIPT_H

#include "Cont.h"
#include "Product.h"
#include"Work.h"
#include "ReceiptLine.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;


class TReceipt {
private:
	long index;
	TDate date;
	TTime time;
	TCont <TReceiptLine> lines;
public:
	TReceipt();
	TReceipt();
	void AddProduct(TProduct product);
	void DeleteProduct(TProduct product);
};

struct TDate {
	int year;
	int month;
	int day;
	TDate() {
		year = timeinfo->tm_year + 1900;
		month = timeinfo->tm_mon +
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			1;
		day = timeinfo->tm_mday;
	}
};
 
struct TTime {
	int hour;
	int minute;
	int second;
	TTIme() {
		hour = 0;
		minute = 0;
		second = 0;
	}
};

#endif 

