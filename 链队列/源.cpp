#include<iostream>
#define MAX_QUEUE_SIZE 10
using namespace std;

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode, * QueuePtr;

typedef struct {
	QueuePtr front;                                       //ͷָ��
	QueuePtr rear;                                          //βָ��
}LinkQueue;

void InitQueue(LinkQueue *ptr) {
	ptr->front = new QNode;                                //����һ��ͷ�ڵ�
    ptr->rear = ptr->front;                                           //ͷβָ�붼ָ��ͷ�ڵ�
	ptr->front->next = nullptr;
}

void EnQueue(LinkQueue* ptr, int e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = nullptr;
	ptr->rear->next = p;
	ptr->rear = p;
}

void DeQueue(LinkQueue* ptr) {
	if (ptr->front == ptr->rear)
		cout << "����Ϊ�գ�" << endl;
	else{
		QNode* p = ptr->front->next;
		ptr->front->next = p->next;
		if (ptr->rear = p)
			ptr->rear = ptr->front;
		delete p;
	}
}

void Display(LinkQueue* ptr) {
	QNode* p = ptr->front->next;
	while (p != nullptr) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	LinkQueue* Q=new LinkQueue;
	int e;
	InitQueue(Q);
	cin >> e;
	while (e != -1) {
		EnQueue(Q, e);
		cin >> e;
	}
	Display(Q);
	DeQueue(Q);
	Display(Q);
	cout << "ȡ��ͷԪ�أ�" << Q->front->next->data<<" "<< endl;
	return 0;
}