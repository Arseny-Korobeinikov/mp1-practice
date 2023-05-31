#include "Cont.h"
#include "Receipt.h"
#include "Product.h"
#include "Work.h"
#include "ReceiptLine.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void TReceipt:: AddProduct(TProduct product) {
	for (int i = 0; i < lines.GetSize(); i++) {
		if (lines[i].GetNamepr() == product.GetName()) {
			lines[i].AddProduct();
			return;
		}
		else lines.Insert(TReceiptLine(product));
	}
}

void TReceipt::DeleteProduct(TProduct product) {
	for (int i = 0; i < lines.GetSize(); i++) {
		if (lines[i].GetNamepr() == product.GetName()) {
			lines[i].DeleteProduct();
			if (lines[i].GetK == 0) {
				lines.Del (i);
			}
			return;
		}
		else {
			string exp = "У вас нет этого товара в чеке, вы не можете его удалить";
			throw exp;
		}
	}
}


TReceipt::TReceipt() {
	index = 0;
	date = TDate();
	time = TTime();
	lines = TCont<TReceiptLine>();
}

