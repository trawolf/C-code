//#ifdef TIMETYPE_H
#define TIMETYPE_H
#pragma once
class TimeType
{
protected:
	int hours, minuts, seconds;  //ʱ���֣���
public:
	TimeType(int , int , int );  //���캯��1
	TimeType();  //���캯��2
	bool equal(TimeType );  //�ж���ʱ���Ƿ����
	void printTime();  //��Ļ���ʱ�������й����ݣ�ʱ���֡��룩
};

//#endif
