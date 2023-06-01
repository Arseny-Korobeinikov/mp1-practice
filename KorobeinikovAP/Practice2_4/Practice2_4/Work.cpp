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

TCont<TProduct> ReadFileBase(const string& file_path) {
	ifstream file;
	file.open(file_path);
	if (!file.is_open()) {
		cout<<"\nRead file error.\n";
	}

	TCont<TProduct> Base(10, 1);
	string tmp;

	while ( !file.eof() ) {
		TProduct current_product;
		current_product = ReadProductEntity(file);
		Base.Insert(current_product);
		getline(file, tmp);
	}

	file.close();
	return Base;
}


TProduct ReadProductEntity(ifstream& file) {

	string code_s;
	getline(file, code_s);  

	string name;
	getline(file, name);

	string cost_s;
	getline(file, cost_s);   
	float cost = stof(cost_s);

	TProduct new_pr(code_s, name, cost);
	return new_pr;
}



TProduct ScanProduct(TCont<TProduct> Base) {
	string tmp;
	cin >> tmp;
	for (int i = 0; i < Base.GetSize(); i++) {
		if (Base[i].GetCode() == tmp) {
			return Base[i];
		}
	}
	string exp = "Incorrect product's code";
	throw exp;
}


TCont<TReceipt> f_work(TCont<TProduct> Base) {
	TCont<TReceipt> checks;

	while (1) {
		cout << "Welcome! Scan your products" << endl;
		TProduct current_pr = ScanProduct(Base);
		TReceipt chek;
		chek.AddProduct(current_pr);
		int flag = 1;
		while (flag == 1) {
			cout << "Что вы желаете сделать? \n1 - Добавить товар в чек \n"
				<< "2 - Удалить единицу товара из чека \n"
				<< "3 - Закончить покупку и распечатать чек" << endl;
			char h;
			cin >> h;
			switch (h)
			{
			case '1': {
				current_pr = ScanProduct(Base);
				chek.AddProduct(current_pr);
				break;
			}
			case '2': {
				current_pr = ScanProduct(Base);
				chek.DeleteProduct(current_pr);
				break;
			}
			case '3': {
				chek.output();
				flag = 0;
				checks.Insert(chek);
				break;
			}
			default:
				break;
			}
		}
		cout << "Вы хотите выключить кассу? y/n" << endl;
		char tmp;
		cin >> tmp;
		if (tmp == 'y') {
			break;
		}
	}

	return checks;	
}
