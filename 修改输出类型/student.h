#pragma once
#include "Person.h"
#include<string>
#include<iostream>

class Student :
	virtual public Person
{
protected:
    int  sID;  //ѧ��  
public:
    Student(int  id = 0, std::string  name1 = "", char  s = 'M') :Person(name1, s)
    {
        sID = id;
    }
    virtual  void  ShowMe();
    friend  std::istream& operator>>(std::istream& in, Student& p);
};
void  Student::ShowMe() {
    std::cout << "����"<<this->name << std::endl;
    std::cout << "�Ա�"<<this->sex << std::endl;
    std::cout << "ѧ��"<<this->sID<< std::endl;
}
//���cin��������������  
std::istream& operator>>(std::istream& in, Student& p) {
    in >> p.name >> p.sex >> p.sID;
    return in;
}

