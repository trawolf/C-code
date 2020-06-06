#pragma once
#include "Person.h"
#include<iostream>
class Staff :
	virtual public Person
{
protected:
    int  wID;  //������  
public:
    Staff(int  id = 0, std:: string  name1 = "", char  s = 'M') :Person(name1, s)
    {wID = id;}
    virtual    void  ShowMe();
    friend  std::istream& operator>>(std::istream& in, Staff& p);
};
void  Staff::ShowMe() {
    std::cout <<"����"<< this->name << std::endl;
    std::cout << "�Ա�"<<this->sex << std::endl;
    std::cout << "����"<<this->wID << std::endl;
}
//���cin��������������  
std::istream& operator>>(std::istream& in, Staff& p) {
    in >> p.name >> p.sex >> p.wID;
    return in;
}
