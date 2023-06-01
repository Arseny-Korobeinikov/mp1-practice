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
			if (lines[i].GetK() == 0) {
				lines.Del(i);
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
	srand(time(NULL));
	index = rand();
	date = TDate();
	time_ = TTime();
	lines = TCont<TReceiptLine>();
}


int TReceipt::GetIndex() {
	return index;
}

float TReceipt:: Total() {
	float total = 0;
	for (int i = 0; i < lines.GetSize(); i++) {
		total += lines[i].GetSum();
	}
}

void TReceipt::output() {
	cout << "Receipt № " << index << endl;
	cout << setw(15) << left << "Product"
		<< setw(10) << "Count"
		<< setw(10) << "Cost"
		<< endl;
	for (int i = 0; i < lines.GetSize(); i++) {
		lines[i].Print;
	}
	cout << "Total cost: " << Total() << endl;
	cout << date << " " << time_ << endl;
}