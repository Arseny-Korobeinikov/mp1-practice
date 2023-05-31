#ifndef WORK_H
#define WORK_H

#include "Cont.h"
#include "Receipt.h"
#include "Product.h"
#include <string>

using namespace std;



#include "Cont.h"
#include "Receipt.h"
#include "Product.h"
#include <string>


TCont<TProduct> ReadFileBase(const string& file_path);
TProduct ReadProductEntity(ifstream& file);


TProduct ScanProduct(TCont<TProduct> Base);


#endif