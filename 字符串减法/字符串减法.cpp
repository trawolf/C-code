// �ַ�������  .cpp
/*
�����������������дһ�����������ַ���A���ַ���B���м������������������ǽ�A�����е�B����ɾ����
������������������ַ���ָ�룬
����ԭ�����£�char* func(char* A, char* B);
��������ʽ��
�ַ���A
�ַ���B
�������ʽ��
����������ַ���
����������һ��
aaabbb
bb
���������һ��
aaab
�������������
aabbababb
ab
�������������
abb
������˵���� ���������������ַ����ĳ��Ⱦ�С��20����0
�����ֱ�׼�������������ƽ�����
��ע�⡿����ʹ��strlen()����strcpy()�����ȣ������벻Ҫֱ��ʹ�ò����ַ����ĺ���
*/

#include<iostream>
#include<cstring>
using namespace std;

char* func(char* , char* );

int main() 
{
    char  a[20], b[20];
    cin >> a >> b;
    char* res = func(a, b);
    cout << res << endl;
	return 0;
}

char* func(char* A, char* B) {
    int steps = strlen(A);
    for (int i = 0; i <steps; i++) {
        int count = 0;
        for (int j = i; j <i+ strlen(B); j++) {
            if (A[j] == B[j - i]) {
                count++;
            }
            else { break; }
        }
        if (steps - i< strlen(B)) {
            break;
        }
        else {
            if (count == strlen(B)) {
                for (int m = i; m < steps - strlen(B); m++) {
                    A[m] = A[m + strlen(B)];
                }
                steps -= strlen(B);
                i--;
            }
            else { continue; }
        }
    }
    char* result = new char[steps];
    for (int i = 0; i < steps; i++) {
        result[i] = A[i];
    }
    result[steps] = '\0';
    return result; 
}