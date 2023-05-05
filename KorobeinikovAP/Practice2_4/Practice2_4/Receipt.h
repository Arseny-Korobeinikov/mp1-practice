#ifndef RECEIPT_H

#define RECEIPT_H
#include "Cont.h"
#include "Product.h"


class Receipt {
	long index;
	TDate date;
	TTime time;
	TCont <TProducts> products;
};

struct TDate {
	int year;
	int month;
	int day;
};
 
struct TTime {
	int hour;
	int minute;
	int second;
};
#endif 

