/*
����һ���򵥵�ѧУ��Ա����ϵͳ��������ѧ����Ա������ְѧ��������Ա������ѧ�����Ĺ�����Ҫ������¹��ܣ�
1������һ��School��,�����ж���������Ա��Append������
2������һ������Person�࣬Ҫ�����������Ա�����ԣ������������ShowMe()����Ϊ�麯����
3������һ��Ա��Staff���һ��ѧ����Student������Person�̳ж�����Ҫ��������Ա���ࣨѧ���ࣩ��������ԣ��������Ա�͹���֤���루��ѧ��ѧ�ţ����ֱ�д����ShowMe()�����ľ���ʵ�֡�
4������һ����ְѧ����Staff_Student�࣬��Ա�����ѧ����̳ж�����д����ShowMe()�����ľ���ʵ�֣���������������ԣ���
5�����أ�ʵ����cinΪԱ���ࡢѧ�������ְѧ�������ֵ��
6����дmain�����������������������ܡ�
*/

/*
���������롿
Tom M 101
Andy F 10002
Jesson M 10003 102
�����������
����:Tom
�Ա�:M
����:101

����:Andy
�Ա�:F
ѧ��:10002

����:Jesson
�Ա�:M
ѧ��:10003
����:102
*/

#include<iostream>
#include"School.h"
#include"Staff.h"
#include"Staff_Student.h"
#include"student.h"

int  main()
{
	School  sch;
	Staff  s1;
	std::cin >> s1;
	sch.append(s1);
	Student  st1;
	std::cin >> st1;
	sch.append(st1);
	Staff_Student  ss1("SS1", 'F', 1001, 1003);
	std::cin >> ss1;
	sch.append(ss1);
	sch.display();
	return  0;
}