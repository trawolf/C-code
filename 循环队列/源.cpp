#include<iostream>
using namespace std;
#define MAX_QUEUE_SIZE 10

typedef struct queue{
	int count;                                              //���г���
	int* base;                                             //��ʼ���Ķ�̬����洢�ռ�
	int front;                                             //ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;                                               //βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}SqQueue;

void InitQueue(SqQueue* ptr) {
	ptr->front = ptr->rear =ptr->count = 0;
	ptr->base = new int[MAX_QUEUE_SIZE];
}

int QueueLength(SqQueue *Q) {                           //����Q��Ԫ�ظ����������г���
	return Q->count;
}

bool QueueFull(SqQueue *Q) {                                 //�ж�Q�Ƿ���
	return QueueLength(Q) >= MAX_QUEUE_SIZE;
}
bool QueueEmpty(SqQueue *Q) {                              //�ж�Q�Ƿ�Ϊ��
	return QueueLength(Q) <= 0;
}

void EnQueue(SqQueue* Q, int e) {                             //���
	if (QueueFull(Q))
		cout << "��������!" << endl;
	else {
		Q->count++;
		Q->base[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
	}
}

void DeQueue(SqQueue* Q) {                           //����
	if (QueueEmpty(Q))
		cout << "����Ϊ��!" << endl;
	else {
		Q->count--;
		Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
	}
}

void Display(SqQueue* ptr) {
	if (QueueEmpty(ptr))
		cout << "����Ϊ�գ�" << endl;
	else {
		int i = ptr->front;
		while (i != ptr->rear) {
			cout << ptr->base[i] << " ";
			i++;
			i = i % MAX_QUEUE_SIZE;
		}
	}
	cout << endl;
}

int main()
{
	SqQueue* input = (SqQueue*)malloc(sizeof(int));
	InitQueue(input);
	EnQueue(input, 11);
	EnQueue(input, 5);
	EnQueue(input, 23);
	EnQueue(input,18);
	DeQueue(input);
	Display(input);
	EnQueue(input,33);
	DeQueue(input);
	Display(input);
	EnQueue(input, 77);
	Display(input);
	return 0;
}