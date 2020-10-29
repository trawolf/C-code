#include<iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;
#define MAX 20			//����ʽ�������


typedef struct  	//�����Ŷ���ʽ����������
{
    double coef;		//ϵ��
    int expn;			//ָ��
} PolyArray;

typedef struct pnode	//���嵥���������ͣ��������ʽ�е�һ������ɶ���ʽ
{
    double coef;		//ϵ��
    int expn;			//ָ��
    struct pnode* next;
} PolyNode;

void PrintPoly(PolyNode* L)	//�������ʽ
{
    bool first = true;		//firstΪtrue��ʾ�ǵ�һ��
    PolyNode* p = L->next;
    while (p != NULL)
    {
        if (first)
            first = false;
        else if (p->coef > 0||p->coef==0)
            cout << "+";
        if (p->coef != 0) {
            if (p->expn == 0)
                cout << p->coef;
            else if (p->expn == 1)
                cout << p->coef << "x";
            else
                cout << p->coef << "x^" << p->expn;
        }
        else cout << "0";
        p = p->next;
    } 
    cout << endl;
}

/*int GetLength(PolyNode& p) {
    int length = 1;
    while (p.next != nullptr)
        length++;
    return length;
}
*/

void DestroyList(PolyNode*& L)	//���ٵ�����
{
    PolyNode* p = L, * q = p->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
    free(p);
}

void CreateListR(PolyNode*& L, PolyArray a[], int n) //β�巨����
{
    PolyNode* s, * r;
    int i;
    L = (PolyNode*)malloc(sizeof(PolyNode));	//����ͷ���
    L->next = NULL;
    r = L;						//rʼ��ָ���ն˽��,��ʼʱָ��ͷ���
    for (i = 0; i < n; i++)
    {
        s = (PolyNode*)malloc(sizeof(PolyNode));//�����½��
        s->coef = a[i].coef;
        s->expn = a[i].expn;
        r->next = s;				//��*s����*r֮��
        r = s;
    }
    r->next = NULL;				//�ն˽��next����ΪNULL
}

void Sort(PolyNode*& head)		//��exp��ݼ�����
{
    PolyNode* p = head->next, * q, * r;
    if (p != NULL)				//��ԭ����������һ�������ϵ����ݽ��
    {
        r = p->next;				//r����*p����̽���ָ��
        p->next = NULL;			//����ֻ��һ�����ݽ��������
        p = r;
        while (p != NULL)
        {
            r = p->next;			//r����*p����̽���ָ��
            q = head;
            while (q->next != NULL && q->next->expn > p->expn)
                q = q->next;		//����������Ҳ���*p��ǰ�����*q
            p->next = q->next;	//��*p���뵽*q֮��
            q->next = p;
            p = r;
        }
    }
}

void Check(PolyNode*& p) {
    for (PolyNode* i = p; i != NULL; i = i->next) {
        for (PolyNode* j = i->next; j != NULL; j = j->next) {
            if (i->expn == j->expn) {
                j->coef += i->coef;            //ָ����ͬϵ�����
                PolyNode* c = p;
                while (c->next && c->next != i)
                    c = c->next;                   //ȷ��i��ֱ��ǰ��
                c->next = c->next->next;
                c->next->next = NULL;    //���б���ɾ��i
            }
        }
    }
}

void AddPolyn(PolyNode* ha, PolyNode* hb, PolyNode*& hc)  //�������򼯺ϵĲ�����ɼӷ�
{
    PolyNode* pa = ha->next, * pb = hb->next, * s, * tc;
    double c;
    hc = (PolyNode*)malloc(sizeof(PolyNode));		//����ͷ���
    tc = hc;
    while (pa != NULL && pb != NULL)
    {
        if (pa->expn > pb->expn)
        {
            s = (PolyNode*)malloc(sizeof(PolyNode));	//���ƽ��
            s->expn = pa->expn;
            s->coef = pa->coef;
            tc->next = s;
            tc = s;
            pa = pa->next;
        }
        else if (pa->expn < pb->expn)
        {
            s = (PolyNode*)malloc(sizeof(PolyNode));	//���ƽ��
            s->expn = pb->expn;
            s->coef = pb->coef;
            tc->next = s;
            tc = s;
            pb = pb->next;
        }
        else				//pa->exp=pb->exp
        {
            c = pa->coef + pb->coef;
            if (c != 0)		//ϵ��֮�Ͳ�Ϊ0ʱ�����½��
            {
                s = (PolyNode*)malloc(sizeof(PolyNode));	//���ƽ��
                s->expn= pa->expn;
                s->coef = c;
                tc->next = s;
                tc = s;
            }
            pa = pa->next;
            pb = pb->next;
        }
    }
    if (pb != NULL) pa = pb;	//�������µĽ��
    while (pa != NULL)
    {
        s = (PolyNode*)malloc(sizeof(PolyNode));	//���ƽ��
        s->expn = pa->expn;
        s->coef = pa->coef;
        tc->next = s;
        tc = s;
        pa = pa->next;
    }
    tc->next = NULL;
}

void MultiplyPolyn(PolyNode* ha, PolyNode* hb, PolyNode*& hc) {
    PolyNode* pa = ha->next, * pb = hb->next, * tc, * s;
    hc = (PolyNode*)malloc(sizeof(PolyNode));		//����ͷ���
    tc = hc;
   while(pa!=NULL){
       while ( pb != NULL) {
           s = (PolyNode*)malloc(sizeof(PolyNode));	//���ƽ��
           s->coef = pa->coef * pb->coef;
           s->expn = pa->expn + pb->expn;
           tc->next = s;
           tc = s;
           pb = pb->next;
       }
       pa = pa->next;
       pb = hb->next;
    }
   tc->next = NULL;
   Sort(hc);
   Check(hc);
}

void ParPolyn(PolyNode* ha, PolyNode*& hc) {
    PolyNode* pa = ha->next, *s, * tc;
    hc = (PolyNode*)malloc(sizeof(PolyNode));
    tc = hc;
    while (pa != NULL) {
        s = (PolyNode*)malloc(sizeof(PolyNode));
        s->coef = pa->coef * pa->expn;
        s->expn = pa->expn - 1;
        tc->next = s;
        tc = s;
        pa = pa->next;
    }
    tc->next = NULL;
}

int main()
{
    PolyNode* ha, * hb, * hc, * hd, * he;
    PolyArray* a = new PolyArray[MAX];
    PolyArray * b=new PolyArray[MAX];

    cout << "�����һ������ʽ�Ĳ���: "<<endl ;
    int judge1 = 0, count1 = 0;
    while (judge1 == 0) {
        int coef, expn;
        cin >> coef >> expn;
        a[count1].coef = coef;
        a[count1].expn = expn;
        count1++;
        char YesorNo;
        cout << "�Ƿ��������";
        cin >> YesorNo;
        if (YesorNo == 'y')
            judge1 = 0;
        else judge1 = 1;
    }

    cout << "����ڶ�������ʽ�Ĳ�����"<<endl ;
    int judge2 = 0, count2 = 0;
    while (judge2 == 0) {
        int coef, expn;
        cin >> coef >> expn;
        b[count2].coef = coef;
        b[count2].expn = expn;
        count2++;
        char YesorNo;
        cout << "�Ƿ��������";
        cin >> YesorNo;
        if (YesorNo == 'y')
            judge2 = 0;
        else judge2 = 1;
    }
   
    CreateListR(ha, a, count1);
    CreateListR(hb, b, count2);
    cout << "ԭ����ʽA:   ";
    PrintPoly(ha);
    cout << "ԭ����ʽB:   ";
    PrintPoly(hb);

    Sort(ha);
    Check(ha);
    cout << "�������ʽA: ";
    PrintPoly(ha);
    Sort(hb);
    Check(hb);
    cout << "�������ʽB: ";
    PrintPoly(hb);

    AddPolyn(ha, hb, hc);
    cout << "����ʽ���:  ";
    PrintPoly(hc);

    MultiplyPolyn(ha, hb, hd);
    cout << "����ʽ��ˣ�";
    PrintPoly(hd);

    ParPolyn(ha, he);
    cout << "��һ������ʽ��һ�׵���";
    PrintPoly(he);

    DestroyList(ha);
    DestroyList(hb);
    DestroyList(hc);
    DestroyList(hd);
    DestroyList(he);
    return 0;
}