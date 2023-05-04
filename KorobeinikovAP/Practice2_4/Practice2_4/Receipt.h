#ifndef RECEIPT_H

#define RECEIPT_H
#include "Cont.h"


class Receipt {
	long index;
	TDate date;
	TTime time;
	TCont <TProducts> products;
};

struct TDate {


};
 
struct TTime {

};
#endif 

