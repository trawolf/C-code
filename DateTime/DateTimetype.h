#pragma once
#include"DateType.h"
#include"TimeType.h"
class DateTimetype :
	public TimeType, public DateType
{
public:
	DateTimetype(int, int, int, int, int, int);  //���캯��1
	DateTimetype();  //���캯��2
	void incrementSecond(int);  //����������
	void printDateTime();  //��Ļ�������ʱ�������й�����
};

