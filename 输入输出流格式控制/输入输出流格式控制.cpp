//����10������������С������������
/*
������ĸ������ݷֳ��������ֺ�С�����֣����У����������Ҷ��룬ʹ��'>'��䣬���ң������ȱ����е��������ֵ��ֵ��Ҫ��3λ��
Ȼ��������ո�+�ո񡹣����������С�����֡�
*/
#include  <iostream>
#include  <iomanip>
#include  <cmath>
#include  <float.h>
//  #include  <string>
using  std::cout;
using  std::cin;
using  std::endl;
using  std::setw;
using  std::setfill;
using  std::right;
using  std::left;
//  using  std::string;
//  using  std::getline;
//enter your code here 


int main(void)
{
    const  int  LENGTH = 10;
    double  arrFloat[LENGTH];
    //  int  arrDigits[LENGTH];
    for (int i = 0; i < LENGTH; ++i) {
        cin >> arrFloat[i];
    }
    //enter your code here
    for (int i = 0; i < LENGTH; i++) {
        double ints;
        double floats = modf(arrFloat[i], &ints);
        cout.fill('>');
        cout << setw(6) << ints << " + " << floats;
        cout << endl;
    }
    return 0;
}