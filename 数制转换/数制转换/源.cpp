#include<iostream>
#include<stack>
#include<fstream>
#define MAX 100000
using namespace std;

void conversion(int n, int d) {              //��ʮ��������nת��Ϊd��������
	stack<int>sq;
	int k;
	while (n > 0) {
		k = n % d;
		n /= d;
		sq.push(k);
	}
	while (!sq.empty()) {
		cout << sq.top();
		sq.pop();
	}
	cout << endl;
}

int main()
{
	ifstream infile1("C:\\Users\\59217\\Desktop\\����\\���ݽṹ����\\���Ĵ��ϻ���ҵ\\��ҵ4���ݼ�v0.2\\����ת��\\dec.txt");
	int* nums = new int[MAX];
	for (int i = 0; i < MAX; i++) {
		infile1 >> nums[i];
		cout << "��ת��ʮ��������";
		cout << nums[i] << endl;
		cout << "�������������";
		conversion(nums[i], 2);
		cout << "����˽�������";
		conversion(nums[i], 8);
		cout << "���ʮ����������";
		conversion(nums[i], 16);
		cout << endl;
	}
	return 0;
}