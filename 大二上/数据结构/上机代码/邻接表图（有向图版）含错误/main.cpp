#include <iostream>
#include <windows.h>
#include "Graph.h"
#include "Edgenode.h"
#include "Vertex.h"
using namespace std;

void ShowMenu(int i)
{
    switch(i)
    {
    case 0:
        cout<<endl
        <<"1) ����ͼ��������_��������������ͼ���������0"<<endl
        <<"2) ��ӡͼ"<<endl
        <<"3����ѯȨֵ����_��_��"<<endl
        <<"4������ߣ���_��_Ȩֵ��"<<endl
        <<"5��ɾ���ߣ���_��_��"<<endl
        <<"6�������һ���ڽӶ��㣨Ŀ�궥�㣩"<<endl
        <<"7��������ȱ�������ʼ���㣩"<<endl
        <<"8��������ȱ�������ʼ���㣩"<<endl
        <<"9����ʾȫ����ͨ����"<<endl
        <<"10����ʾ��ͨ��������"<<endl
        <<"0���˳�"<<endl;
        break;
    }
}

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    Graph* G;

    ShowMenu(0);

    int operation=0;
    cin>>operation;

    while(operation)
    {
        int x,y,z;
        switch(operation)
        {
        case 1:
            cin>>x>>y;
            G=new Graph;
            G->create(x,y);
            G->ShowGraph();
            break;
        case 2:
            G->ShowGraph();
            break;
        case 3:
            cin>>x>>y;
            cout << G->getweight(x,y);
            break;
        case 4:
            cin>>x>>y>>z;
            G->insertEdge(x,y,z);
            G->ShowGraph();
            break;
        case 5:
            cin>>x>>y;
            G->deleteEdge(x,y);
            G->ShowGraph();
            break;
        case 6:
            cin>>x;
            cout << G->findFirstadj(x);
            break;
        case 7:
            cin>>x;
            G->depthFirstTraverse(x);
            break;
        case 8:
            cin>>x;
            G->broadFirstTraverse(x);
            break;
        case 9:
            G->findcomponent();
            break;
        case 10:
            cout << G->countcomponent();
            break;
        }

        ShowMenu(0);
        cin>>operation;
    }

    return 0;
}
