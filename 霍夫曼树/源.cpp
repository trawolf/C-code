#include<iostream>
#include<algorithm>
#include<deque>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

template<typename T>
struct HuffmanNode {
	T key;                                         //����ֵ
	HuffmanNode<T>* lchild;               //�ڵ������
	HuffmanNode<T>* rchild;               //�ڵ���Һ���
	HuffmanNode ( T k, HuffmanNode<T>* l = nullptr, HuffmanNode<T>* r = nullptr)
	          :key(k), lchild(l), rchild(r){}
	~HuffmanNode() {};
};
template<typename T>
class Huffman {
private:
	Huffman<T>* root;
	deque<HuffmanNode<T>*>forest;             //ɭ��

	void inOrder(HuffmanNode<T>* pnode);
	void print(HuffmanNode<T>* pnode);
	void destroy(HuffmanNode<T>* pnode);
public:
	Huffman();
	~Huffman() ;
	void inOrder();
	void creat(T a[], int size);                 //������������
	void destroy();
	void print();
};

template<typename T>
Huffman<T>::Huffman() :root (nullptr){};

template<typename T>
Huffman<T>::~Huffman() { 
	destroy(root); 
};

template<typename T>
void Huffman<T>::creat(T a[], int size) {
	for (int i = 0; i < size; i++) {
		HuffmanNode<T>* ptr = new HuffmanNode<T>(a[i], nullptr, nullptr);
		forest.push_back(ptr);
	}
	for (int j = 0; j < size - 1; j++) {
		sort(forest.begin(), forest.end(), [](HuffmanNode<T>* a, HuffmanNode<T>* b) {return a->key < b->key; });
		HuffmanNode<T>* node = new HuffmanNode<T>(forest[0]->key + forest[1]->key, forest[0], forest[1]);
		forest.push_back(node);
		forest.pop_front();
		forest.pop_front();
	}
	root = forest.front();
	forest.clear();
};

template<typename T>
void Huffman<T>::inOrder(HuffmanNode<T>* pnode) {
	if (pnode != nullptr) {
		inOrder(pnode->lchild);
		cout << pnode->key;
		inOrder(pnode->rchild);
	}
};
template<typename T>
void Huffman<T>::inOrder() {
	inOrder(root);
}

template<typename T>
void Huffman<T>::print(HuffmanNode<T>* pnode) {
	if (pnode != nullptr) {
		cout << "��ǰ�ڵ㣺" << pnode->key << ".";
		if (pnode->lchild != nullptr)
			cout << "�������ӽڵ�Ϊ��" << pnode->lchild << ".";
		else cout << "��û������.";
		if (pnode->rchild != nullptr)
			cout << "�����Һ��ӽڵ�Ϊ��" << pnode->rchild << ".";
		else cout << "��û���Һ���.";
		cout << endl;
		print(pnode->lchild);
		print(pnode->rchild);
	}
};
template<typename T>
void Huffman<T>::print() {
	print(root);
};

template<typename T>
void Huffman<T>::destroy(HuffmanNode<T>* pnode) {
	if (pnode != nullptr) {
		destroy(pnode->lchild);
		destroy(pnode->rchild);
		delete pnode;
		pnode = nullptr;
	}
};
template<typename T>
void Huffman<T>::destroy() {
	destroy(root);
}

int main()
{
	ifstream infile1("C:\\Users\\59217\\Desktop\\����\\���ݽṹ����\\�ھŴ��ϻ���ҵ\\�����������������\\Document.txt");
	string str,res;
	while (infile1>>str) {
		res += str;
	}
	int size = res.length(), i = 0;
	
	return 0;
}