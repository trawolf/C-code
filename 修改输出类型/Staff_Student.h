#pragma once
#include"Staff.h"
#include"student.h"
#include<iostream>
class Staff_Student :
	 public Staff ,  public Student, virtual public Person
{
public:
    Staff_Student(std::string  name1 = "", char  s = 'M', int  id1 = 0, int  id2 = 0) :Person(name1, s), Student(id1, name1, s), Staff(id2, name1, s)
    {    };
    virtual  void  ShowMe();
    friend  std::istream& operator>>(std::istream& in, Staff_Student& p);
};
void  Staff_Student::ShowMe() {
    std::cout << "����"<<Person::name << std::endl;
    std::cout << "�Ա�"<<Person::sex << std::endl;
    std::cout << "ѧ��"<<this->sID << std::endl;
    std::cout << "����"<<this->wID << std::endl;
}
//���cin��������������  
std::istream& operator>>(std::istream& in, Staff_Student& p) {
    in >> p.Person::name >> p.Person::sex >> p.sID >> p.wID;
    return in;
}


