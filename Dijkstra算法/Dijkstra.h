#pragma once

#include<iostream>
#include<string>
using namespace std;

struct Dis {
	string path;
	int value;
	bool visit;
	Dis(){
		visit = false;
		value = 0;
		path = " ";
	}
};

class Graph_DG 
{
private:
	int vexnum;               //ͼ�Ķ������
	int edge;                     //ͼ�ı���
	int** arc;                    //�ڽӾ���
	Dis* dis;                       //��¼�����������·������Ϣ
public:
	Graph_DG(int vexnum, int edge);
	~Graph_DG();
	bool check_edge_value(int start, int end, int weight);
	void creatGraph();
	void print();
	void Dijkstra(int begin);
	void print_path(int);
};

