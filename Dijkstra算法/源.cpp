#include<iostream>
#include"Dijkstra.h"
using namespace std;

bool check(int Vexnum, int edge) {
    if (Vexnum <= 0 || edge <= 0 || ((Vexnum * (Vexnum - 1)) / 2) < edge)
        return false;
    return true;
}
int main() {
    int vexnum; int edge;

    cout << "����ͼ�Ķ�������ͱߵ�������" << endl;
    cin >> vexnum >> edge;
    while (!check(vexnum, edge)) {
        cout << "�������ֵ���Ϸ�������������" << endl;
        cin >> vexnum >> edge;
    }
    Graph_DG graph(vexnum, edge);
    graph.creatGraph();
    graph.print();
    graph.Dijkstra(1);
    graph.print_path(1);
    system("pause");
    return 0;
}
