/*
��ӡrow��row�е�����ƽ���������з�����������"|"�ַ�ǰ�����Ϊ5���к�֮�����Ϊ5��������֮�������Ϊ�߸�"-"�ַ���
���з��棬�к����Ϊ2��"|"�ַ����Ϊ3��ƽ����������Ϊ7������λ��������ӡ��
*/
/*
cout<<setw(5)<<"|";
for(i=0;i<row;i++) cout<<setw(5)<<i<<"  "; //2���ո�
cout<<endl<<"----+";
for(i=0;i<row;i++) cout<<"-------"; //7����-���ַ�
*/

#include<iostream>
#include<iomanip>
#include<math.h>
using std::cout;
using std::setw;

int main()
{
	int row;
	std::cin >> row;
	cout << setw(5) << "|";
	for (int i = 0; i < row; i++) cout << setw(5) << i << "  "; //2���ո�
	cout << std::endl << "----+";
	for (int i = 0; i < row; i++) cout << "-------"; //7����-���ַ�
	for (int i = 0; i < row; i++) {
		cout << std::endl<< setw(2) << i << "  |";
		cout.setf(std::ios::fixed, std::ios::floatfield);//���ö����ʽ
		cout.precision(3);
		for (int j = 0; j < row; j++)cout << setw(7) << sqrt(i * 10 + j);
	}
	return 0;
}