#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
using namespace std;
#define ElemType int
#define maxsize 100
#define InfoType int
#define MAXV 100
#define MaxSize 100
#define INF 214748364 
#define INFINITE INF

typedef struct ANode
{
    int adjvex;            //�ñߵ��ڽӵ�ı�ţ��������ָ��Ķ�����
    struct ANode* nextarc; //ָ����һ���ߵ�ָ��
    int weight;            //�ߵ���ص���Ϣ����Ȩֵ
} ArcNode;                 //�߽ڵ������

typedef struct Vnode
{
    InfoType info;     //�����������Ϣ
    int count;         //��Ŷ������
    ArcNode* firstarc; //ָ���һ���߽ڵ�
} VNode;               //�ڽӱ��ͷ�ڵ�Ľṹ������

typedef struct
{
    VNode adjlist[MAXV]; //ͷ�ڵ������
    int n, e;            //ͼ�Ķ������ͱ���
} AdjGraph;              //�����ڽӱ�����ݽṹ������

typedef struct SSS
{
    ElemType data[maxsize];
    int front;
    int rear;
} SqQueue; //���еĽṹ��

typedef struct head
{
    int u; //�ߵ���ʼ����
    int v; //�ߵ���ֹ����
    int w; //�ߵ�Ȩֵ
} Edge;

int visited[MAXV] = { 0 };

void InitQueue(SqQueue*& q);
void DestoryQueue(SqQueue*& q);
bool QueueEmpty(SqQueue* q);
bool enQueue(SqQueue*& q, ElemType e);
bool deQueue(SqQueue*& q, ElemType& e);

void InitQueue(SqQueue*& q)
{
    q = (SqQueue*)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}

void DestoryQueue(SqQueue*& q)
{
    free(q);
}

bool QueueEmpty(SqQueue* q)
{
    return (q->front == q->rear);
}

bool enQueue(SqQueue*& q, ElemType e)
{
    if ((q->rear + 1) % maxsize == q->front)
        return false;
    q->rear = (q->rear + 1) % maxsize;
    q->data[q->rear] = e;
    return true;
}

bool deQueue(SqQueue*& q, ElemType& e)
{
    if (q->front == q->rear)
        return false;
    q->front = (q->front + 1) % maxsize;
    e = q->data[q->front];
    return true;
}

void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode* p;
    G = (AdjGraph*)malloc(sizeof(AdjGraph));
    for (i = 0; i < n; i++) {
        G->adjlist[i].firstarc = NULL;
    }
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= 0; j--) {
            if (A[i][j] != 0 && A[i][j] != INF)
            {
                p = (ArcNode*)malloc(sizeof(ArcNode));
                p->adjvex = j;
                p->weight = A[i][j];
                p->nextarc = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n;
    G->e = e;
}

void DispAdj(AdjGraph* G) //����ڽӱ�G
{
    int i;
    ArcNode* p;
    for (i = 0; i < G->n; i++){
        p = G->adjlist[i].firstarc;
        cout << i << ":   ";
        while (p != NULL)
        {
            if (p->weight != 2147483647) 
                cout<<p->adjvex<<'['<<p->weight<<']'<<" ";
            p = p->nextarc;
        }
        cout << endl;
    }
}

void DestroyAdj(AdjGraph*& G) //�����ڽӱ�
{
    int i;
    ArcNode* pre, * p;
    for (i = 0; i < G->n; i++) {
        pre = G->adjlist[i].firstarc; 
        if (pre != NULL)
        {
            p = pre->nextarc;
            while (p != NULL) 
            {
                free(pre);
                pre = p;
                p = p->nextarc;
            }
            free(pre);
        }
    }
    free(G);
}

void DFS(AdjGraph* G, int v)
{
    ArcNode* p;
    visited[v] = 1;
    cout << v<<" ";
    p = G->adjlist[v].firstarc;
    while (p != NULL) 
    {
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}

void BFS(AdjGraph* G, int v)
{
    int w, i;
    ArcNode* p;
    SqQueue* qu;
    InitQueue(qu);
    int visited[MAXV];
    for (i = 0; i < G->n; i++)
        visited[i] = 0;
    cout << v<<" ";
    visited[v] = 1;
    enQueue(qu, v);
    while (!QueueEmpty(qu))
    {
        deQueue(qu, w);
        p = G->adjlist[w].firstarc;
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                cout<<p->adjvex<<" ";
                visited[p->adjvex] = 1;
                enQueue(qu, p->adjvex);
            }
            p = p->nextarc;
        }
    }
    cout << endl;
}

int main()
{
    int a[4][MAXV] = { {0, 1, 1, 1},{1, 0, 1, 1},{1, 1, 0, 0},{1, 1, 0, 0} };
    AdjGraph* g;
    CreateAdj(g, a, 4, 5);
    cout << "����ԭʼ�ڽӱ�Ľṹ:"<<endl;
    DispAdj(g);
    cout << "this is the Deep fist search (from '0'):" << endl;
    DFS(g, 0);
    cout << endl;
    cout<<"this is the Broad fist search (from '0): "<<endl;
    BFS(g, 0);
    system("pause");
    return 0;
}
