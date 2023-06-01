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




int main () {
	TCont<TProduct> Base;
	Base = ReadFileBase("base.txt");

	f_work(Base);

	return 0;
}