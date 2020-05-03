#pragma once
#include"Info.h"
#include<iostream>
using namespace std;

class Database
{
private:
	Info* info;
	int count;  //�����˺�����
	int capacity;  //���ݿ�������
public:
	Database(int cap) {
		this->capacity = cap;
		this->count = 0; 
		this->info = new Info[capacity];
}
	//��info���f��count��һ(���id�ظ��򳬳����ݿ�������ȡ�����)
	bool push_info(Info f) {
		if (count >= capacity) return false;
		else {
			bool yesorno=0;
			for (int i = 0; i < count; i++) {
				if (f == info[i]) {
					yesorno = 1;
					break;
				}
			}
			if (yesorno == 0) {
				info[count] = f;
				count++;
				return true;
			}
			else return false;
		}
	}
	//��ȡidΪm���˺���Ϣ������������ӡ��Ϊһ��
	void get_info(int m) {
		for (int i = 0; i < count; i++) {
			if (info[i].id == m) {
				cout << info[i].id <<" "<< info[i].username <<" "<< info[i].password<<endl;
				break;
			}
		}
	}
	//ɾ��idΪm���˺���Ϣ������m֮�������ǰ�ƣ����ɾ���ɹ�����true�����������idΪm�ģ��򷵻�false
	bool delete_info(int m) {
		 for(int i=0;i<count;i++){
			if (info[i].id == m) {
				for (int j = i; j < count-1; j++) {
					info[j] = info[j + 1];
				}
				count--;
				return true;
				break;
			}
		}
		return false;
	}
};

