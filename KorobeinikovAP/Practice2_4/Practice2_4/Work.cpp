#include "Cont.h"
#include "Receipt.h"
#include "Product.h"
#include"Work.h"
#include "ReceiptLine.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

TCont<TProduct> ReadFileBase(const string& file_path) {
	ifstream file;
	file.open(file_path);
	if (!file.is_open()) {
		cout<<"\nRead file error.\n";
	}

	TCont<TProduct> Base(10, 1);
	string tmp;

	while (!file.eof()) {
		TProduct current_product = ReadProductEntity(file);
		Base.Insert(current_product);
		getline(file, tmp);
	}
	file.close();
	return Base;
}


TProduct ReadProductEntity(ifstream& file) {

	string code_s;
	getline(file, code_s);  //тут сделать строку а не число, окс stroku. a ne chisl

	string name;
	getline(file, name);

	string cost_s;
	getline(file, cost_s);    //сделать флотовыми float no int
	int cost = stoi(cost_s);

	TProduct new_pr(code_s, name, cost);
	return new_pr;
}



TProduct ScanProduct(TCont<TProduct> Base) {
	string tmp;
	cin >> tmp;
	for (int i = 0; i < Base.GetSize(); i++) {
		if (Base[i].GetCode == tmp) {
			return Base[i];
		}
	}
	string exp = "Incorrect product's code";
	throw exp;
}
