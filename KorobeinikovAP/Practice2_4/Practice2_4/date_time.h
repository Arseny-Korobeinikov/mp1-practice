#ifndef DATE_TIME_H
#define DATE_TIME_H

#define _CRT_SECURE_NO_WARNINGS

#include "Cont.h"
#include "Product.h"
#include "ReceiptLine.h"
#include "Receipt.h"
#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;









struct TDate {
	int year;
	int month;
	int day;
	TDate();
	void Print();
	friend ostream& operator<<(ostream& out, const TDate& date) {
		out << setfill('0') << setw(2) << date.day << '.' << setfill('0') << setw(2) << date.month << '.' << date.year;
		return out;
	}
};




struct TTime {
	int hour;
	int minute;
	int second;

	TTime();
	void Print();
	friend ostream& operator<<(ostream& out, const TTime& time) {
		out << setfill('0') << setw(2) << time.hour << ':' << setfill('0') << setw(2) << time.minute << ':'
			<< setfill('0') << setw(2) << time.second;
		return out;
	}
};


#endif