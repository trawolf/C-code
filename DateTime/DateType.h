#pragma once
class DateType
{
protected:
	int years, months, day;  //�꣬�£���
public:
	DateType(int  , int  , int  );  //���캯��1
	DateType();  //���캯��2
	int GetMonthDay(int , int);  //��ø��µ�����
	bool equal(DateType );  //�ж��������Ƿ����
	void printDate();  //��Ļ������ڶ�����й����ݣ��ꡢ�¡��գ�
};

