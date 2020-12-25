#include<iostream>
#include<algorithm>
using namespace std;

int Bin_Search(int* table,int length, int key) {
	int Low = 1, High = length, Mid;
	while (Low <= High) {
		Mid = (Low + High) / 2;
		if (table[Mid] == key)
			return Mid;
		else if (key > table[Mid])
			Low = Mid + 1;
		else
			High = Mid - 1;
	}
	return 0;
}

int main() 
{
	cout << "�������鳤�ȣ�" << endl;
	int length;
	cin >> length;
	cout << "��������Ԫ�أ�" << endl;
	int* p = new int[length];
	for (int i = 0; i < length; i++) {
		cin >> p[i];
	}
	sort(p, p + length);
	cout << "���������Ԫ�أ�" << endl;
	int key;
	cin >> key;
	cout << "���ֲ��ң�" << endl;
	cout << Bin_Search(p, length, key) << endl;
	return 0;
}