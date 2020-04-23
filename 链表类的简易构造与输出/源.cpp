// ������ļ��׹��������   .cpp
//

#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;

class  ListNode {
    friend  class  LinkList;    //����LinkListΪ��Ԫ��
public:
    ListNode() { next = NULL; };
    ListNode(int  x) {
        val = x;
        next = NULL;
    }
private:
    int  val;  //������
    ListNode* next;  //ָ����
};

class  LinkList {
public:
    LinkList(int* arr, int  len);  //���캯��
    ~LinkList();  //��������
    void  Output();
private:
    ListNode* head;//ͷָ�룬ָ���һ�����
};

LinkList::LinkList(int* arr, int  len) {
    head = new ListNode;
    ListNode* b = new ListNode;
    b = head;
    for (int i = 0; i <len; i++) {
        ListNode* a = new ListNode;
        a->val = arr[i];
        a->next = NULL;
        b->next=a;
        b = a;
    }
}

LinkList::~LinkList() {
    cout << "The  LinkList  was  destroyed!" << endl;

}

void  LinkList::Output() {
    ListNode* p = head->next;
    while (p != NULL) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

int    main() {

    int    length;
    cin >> length;
    int* arr = new    int[length];
    for (int i = 0; i < length; i++)
        cin >> arr[i];

    LinkList  linklist(arr, length);
    linklist.Output();
    system("pause");
    return    0;
}
