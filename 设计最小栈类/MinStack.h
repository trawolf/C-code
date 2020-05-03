#pragma once
#include<iostream>

const int length = 100;
class MinStack
{
private:
	int* xx;
	int count = 0;
public:
	MinStack() {
		xx = new int[length];
	}
	//��Ԫ��x����ջ��
	void push(int x) {
		xx[count] = x;
		count++;
	}
	//ɾ��ջ����Ԫ��
	void pop() {
		count--;
	}
	//��ȡջ��Ԫ��
	int top() {
		return xx[count-1];
	}
	//����ջ�е���СԪ��
	int getMin() {
		int min = xx[0];
		for (int i = 1; i < count; i++) {
			if (min >= xx[i]) {
				min = xx[i];
			}
		}
		return min;
	}
};

