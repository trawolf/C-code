#include "DateType.h"
#include<iostream>
using namespace std;

int DateType::GetMonthDay(int year, int month)
{
	//�þ�̬���飬����ÿ�ε��õ�ʱ�򶼿����µ�����
	static int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//���Ϊ����Ļ���2��Ϊ29��
	if ((month == 2) && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{ return 29;}
	else {return monthArray[month];}
}
DateType::DateType(int y0 , int m0 , int d0 ) {
	this->years = y0; this->months = m0; this->day = d0;
}
DateType::DateType() {
	this->years =1; this->months = 1; this->day = 1;
}
bool DateType::equal(DateType dt2) {
	if (this->day == dt2.day && this->months == dt2.months && this->years == dt2.years) 
	{	return true;}
	else { return false; }
}
void DateType::printDate() {
	cout << this->years << "-" << this->months << "-" << this->day << endl;
}