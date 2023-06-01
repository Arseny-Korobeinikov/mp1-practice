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
	TDate() {
		auto now = chrono::system_clock::now();
		auto now_time_t = chrono::system_clock::to_time_t(now);
		auto now_tm = *localtime(&now_time_t);
		year = now_tm.tm_year + 1900;
		month = now_tm.tm_mon + 1;
		day = now_tm.tm_mday;
	}
	void Print() {
		cout << setfill('0') << setw(2) << day << '.' << setfill('0') << setw(2) << month << '.' << year;
	}
	friend ostream& operator<<(ostream& out, const TDate& date) {
		out << setfill('0') << setw(2) << date.day << '.' << setfill('0') << setw(2) << date.month << '.' << date.year;
		return out;
	}
};




struct TTime {
	int hour;
	int minute;
	int second;

	TTime() {
		auto now = chrono::system_clock::now();
		auto now_time_t = chrono::system_clock::to_time_t(now);
		auto now_tm = *localtime(&now_time_t);
		hour = now_tm.tm_hour;
		minute = now_tm.tm_min;
		second = now_tm.tm_sec;
	}
	void Print() {
		cout << setfill('0') << setw(2) << hour << ':' << setfill('0') << setw(2) << minute << ':' << setfill('0') << setw(2) << second;
	}
	friend ostream& operator<<(ostream& out, const TTime& time) {
		out << setfill('0') << setw(2) << time.hour << ':' << setfill('0') << setw(2) << time.minute << ':'
			<< setfill('0') << setw(2) << time.second;
		return out;
	}
};


#endif