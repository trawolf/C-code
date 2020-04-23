#pragma once

#include<iostream>
using namespace std;

class  Date
{
private:
    int  _year;
    int  _month;
    int  _day;
public:
    int  GetMonthDay(int  year, int  month)
    {
        //�þ�̬���飬����ÿ�ε��õ�ʱ�򶼿����µ�����
        static  int  monthArray[13] = { 0,  31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31 };
        //���Ϊ����Ļ���2��Ϊ29��
        if ((month == 2) && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            return  29;
        }
        else
            return  monthArray[month];
    }
    //���캯��
    Date(int  year = 2019, int  month = 1, int  day = 1)
    {
        if (year > 0 &&
            (month > 0 && month < 13) &&
            (day > 0 && day <= GetMonthDay(year, month)))
        {
            _year = year;
            _month = month;
            _day = day;
        }
        else
        {
            cout << "���ڷǷ�" << endl;
            cout << year << "-" << month << "-" << day << endl;
        }
    }
    bool  operator!=(const  Date& d)  const
    {
        if (this->_year == d._year && this->_month == d._month &&this->_day == d._day)
            return false;
        else { return true; }
    }
    Date& operator+=(int  day)
    {
        //�Ƚ�Ҫ�ӵ��������ϣ��ж��Ƿ�Ϸ������Ϸ��ͽ��£��²��Ϸ��ͽ���
        this->_day = this->_day+ day;
        if (this->_day > GetMonthDay(this->_year, this->_month)) {
            this->_month++;
            this->_day = 1;
        }
        if (this->_month > 12) {
            this->_year++;
            this->_month = 1;
        }
        return  *this;
    }
    //  ����-�������Ĭ�ϼ���С�ڱ�����
    int  operator-(const  Date& d)
    {
        Date  Max = (*this);
        Date  Min = d;
        int  day = 0;
        while (Max != Min)
        {
            day++;
            Min += 1;
        }
        return  day;
    }
};

