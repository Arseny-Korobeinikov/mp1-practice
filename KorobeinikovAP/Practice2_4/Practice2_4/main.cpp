


#include "Cont.h"
#include "Receipt.h"
#include "Product.h"
#include"Work.h"
#include "ReceiptLine.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;




int main () {
	TCont<TProduct> Base = ReadFileBase("base.txt");
	cout << "Welcome! Scan your products" << endl;
	TProduct current_pr = ScanProduct(Base);
	TReceipt chek;
	chek.AddProduct(current_pr);
	while (int flag = 1 == 1) {
		cout << "��� �� ������� �������? \n1 - �������� ����� � ��� \n2 - ������� ������� ������ �� ���� \n3 - ��������� ������� � ����������� ���"<<endl;
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
			chek.output;
			break;
		}


		default:
			break;
		}
	}
}