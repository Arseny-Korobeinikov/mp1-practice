#define _CRT_SECURE_NO_WARNINGS

#include "Cont.h"
#include "Receipt.h"
#include "Product.h"
#include "ReceiptLine.h"
#include "date_time.h"
#include <chrono>
#include <string>
#include <fstream>
#include <iostream>
#include<time.h>
#include <iomanip>

using namespace std;


TDate:: TDate() {
	auto now = chrono::system_clock::now();
	auto now_time_t = chrono::system_clock::to_time_t(now);
	auto now_tm = *localtime(&now_time_t);
	year = now_tm.tm_year + 1900;
	month = now_tm.tm_mon + 1;
	day = now_tm.tm_mday;
}
void TDate:: Print() {
	cout << setfill('0') << setw(2) << day << '.' << setfill('0') << setw(2) << month << '.' << year;
}



TTime:: TTime() {
	auto now = chrono::system_clock::now();
	auto now_time_t = chrono::system_clock::to_time_t(now);
	auto now_tm = *localtime(&now_time_t);
	hour = now_tm.tm_hour;
	minute = now_tm.tm_min;
	second = now_tm.tm_sec;
}
void TTime::Print() {
	cout << setfill('0') << setw(2) << hour << ':' << setfill('0') << setw(2) << minute << ':' << setfill('0') << setw(2) << second;
}