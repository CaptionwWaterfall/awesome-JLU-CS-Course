#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "Vertex.h"
#include "Edgenode.h"
#include "Node.h"
#define MAX 1000
using namespace std;
class Graph
{
private:
    Vertex* vertexlist;
    int graphsize;
public:
    Graph(Vertex* tempvertexlist=nullptr,int tempsize=0)
                 :vertexlist(tempvertexlist),graphsize(tempsize) { }
    void ShowGraph()
    {
       cout<<endl;
       for(int i=0;i<graphsize;i++)
       {
           cout<<'['<<vertexlist[i].getvername()<<']';
           Edgenode* e = vertexlist[i].getadjacent();
           while(e!=NULL)
           {
               cout<<"->"<<e->getveradj()<<'('<<e->getweight()<<')';
               e=e->getlink();
           }
           cout<<endl;
       }
    }
    //����ɼ�����
    int** getwashall()
    {
        int** matrix(nullptr);
        matrix = new int*[graphsize];
        for(int i=0;i<graphsize;++i)
        {
            matrix[i] = new int[graphsize];
        }
        for(int j=0;j<graphsize;++j)
        {
            for(int k=0;k<graphsize;++k)
            {
                if(j==k)
                    matrix[j][k] = 1;
                else
                    matrix[j][k] = 0;
            }
        }
        for(int i=0;i<graphsize;i++)
        {
           Edgenode* e = vertexlist[i].getadjacent();
           while(e!=NULL)
           {
               matrix[i][e->getveradj()] = 1;
               e = e->getlink();
           }
        }
    for(int k=0;k<graphsize;k++)
    {
        for(int i=0;i<graphsize;i++)
        {
            if(matrix[i][k]==1)
            {
                for(int j=0;j<graphsize;j++)
                {
                    matrix[i][j]=matrix[i][j]||matrix[k][j];
                }
            }
        }
    }
        return matrix;
    }
    //���ж��ٸ���ͨ����
    int countcomponent()
    {
        int* marked(nullptr);
        marked = new int[graphsize];
        int** washallMatrix;
        washallMatrix = getwashall();
        for(int i=0;i<graphsize;++i)
            marked[i] = 0;
        int t(0);
        for(int i=0;i<graphsize;++i)
        {
            if(marked[i]==0)
            {
                Node* componentList = new Node(i,nullptr);
                t++;
                marked[i] = 1;
                Node* q;
                q = componentList;
                for(int j=0;j<graphsize;++j)
                {
                    if(i!=j&&washallMatrix[i][j]==1&&washallMatrix[j][i]==1)
                    {
                        marked[j] = 1;
                        Node* p = new Node(j,nullptr);
                        q->setlink(p);
                        q = p;
                    }
                }
                //cout << "��" << t << "����ͨ����:";
                while(componentList!=nullptr)
                {
                    //cout << componentList->getvername() << " ";
                    q = componentList;
                    componentList = componentList->getlink();
                    delete q;
                }
                //cout << endl;
            }
        }
        return t;
    }
    //�����ͨ����
    void findcomponent()
    {
        int* marked(nullptr);
        marked = new int[graphsize];
        int** washallMatrix;
        washallMatrix = getwashall();
        for(int i=0;i<graphsize;++i)
            marked[i] = 0;
        int t(0);
        for(int i=0;i<graphsize;++i)
        {
            if(marked[i]==0)
            {
                Node* componentList = new Node(i,nullptr);
                t++;
                marked[i] = 1;
                Node* q;
                q = componentList;
                for(int j=0;j<graphsize;++j)
                {
                    if(i!=j&&washallMatrix[i][j]==1&&washallMatrix[j][i]==1)
                    {
                        marked[j] = 1;
                        Node* p = new Node(j,nullptr);
                        q->setlink(p);
                        q = p;
                    }
                }
                cout << "��" << t << "����ͨ����:";
                while(componentList!=nullptr)
                {
                    cout << componentList->getvername() << " ";
                    q = componentList;
                    componentList = componentList->getlink();
                    delete q;
                }
                cout << endl;
            }
        }
    }
    void create(int asize,int edgenumber)
    {
        srand(time(0));
        graphsize = asize;
        int from(0);
        int to(0);
        int weight(0);
        vertexlist = new Vertex[MAX];
        for(int i=0;i<graphsize;++i)
        {
            vertexlist[i].setvername(i);
            vertexlist[i].setadjacent(nullptr);
        }
        Edgenode* p(nullptr);
        Edgenode* q(nullptr);
        bool flag = true;
        for(int i=0;i<edgenumber;++i)
        {
            cout << "�����������" << i+1 <<
                    "���ߵ���������źʹ˱�Ȩֵ:" << endl;
            cin >> from >> to >> weight;
            p = new Edgenode(to,weight);
            q = vertexlist[from].getadjacent();
            bool flag(true);
            if(q==nullptr)
                vertexlist[from].setadjacent(p);
            else
            {
                //����Ƿ������ظ�
                while(q->getlink()!=nullptr)
                {
                    if(q->getveradj()==to)
                    {
                       cout << "�˱��Ѵ���,����������:" << endl;
                       i--;
                       flag = false;
                       delete p;
                       delete q;
                       break;
                    }
                    q = q->getlink();
                }
                if(flag==true)
                {
                    q->setlink(p);
                }

            }
            /***************************************/
            //����ͼ��˫����
            Edgenode* p1 = new Edgenode(from,weight);
            Edgenode* q1 = vertexlist[to].getadjacent();
            if(q1==nullptr)
                vertexlist[to].setadjacent(p1);
            else
            {
                while(q1->getlink()!=nullptr)
                    q1 = q1->getlink();
                q1->setlink(p1);
            }

        }
    }
    ~Graph()
    {
        for(int i=0;i<graphsize;++i)
        {
            Edgenode* p = vertexlist[i].getadjacent();
            while(p!=nullptr)
            {
                vertexlist[i].setadjacent(p->getlink());
                delete p;
                p = vertexlist[i].getadjacent();
            }
        }
        delete[] vertexlist;
    }
    bool judgeEdge(const int& v1,const int& v2)
    {
        Edgenode* p(nullptr);
        p = vertexlist[v1].getadjacent();
        while(p!=nullptr)
        {
            if(p->getveradj()==v2)
                return true;
            p = p->getlink();
        }
        return false;
    }
    bool insertEdge(const int& v1,const int& v2,int weight)
    {
        if(v1==v2||v1<0||v2<0||v1>graphsize||v2>graphsize)
        {
            cout << "��������!" << endl;
            return false;
        }
        Edgenode* p = new Edgenode;
        p->setveradj(v2);
        p->setweight(weight);
        p->setlink(nullptr);
        Edgenode* q(nullptr);
        q = vertexlist[v1].getadjacent();
        if(q==nullptr)
        {
            vertexlist[v1].setadjacent(p);
        }
        else
        {
            while(q->getlink()!=nullptr)
            {
                if(q->getveradj()==v2)
                {
                    cout << "�˱��Ѵ���" << endl;
                    return false;
                }
                q = q->getlink();
            }
            q->setlink(p);
        }
        /***************************************************/
        //����ͼ��˫����
            Edgenode* p1 = new Edgenode(v1,weight);
            Edgenode* q1 = vertexlist[v2].getadjacent();
            if(q1==nullptr)
                vertexlist[v2].setadjacent(p1);
            else
            {
                while(q1->getlink()!=nullptr)
                    q1 = q1->getlink();
                q1->setlink(p1);
            }
        return true;
    }
    bool deleteEdge(const int& v1,const int& v2)
    {
        if(v1==v2||v1<0||v2<0||v1>graphsize||v2>graphsize)
        {
            cout << "��������!" << endl;
            return false;
        }
        Edgenode* p(nullptr);
        Edgenode* q(nullptr);
        p = vertexlist[v1].getadjacent();
        if(p==nullptr)
        {
            cout << "�ñ߲�����" << endl;
            return false;
        }
        if(p->getveradj()==v2)
        {
            q = p->getlink();
            delete p;
            vertexlist[v1].setadjacent(q);
        }
        else if(p->getveradj()!=v2)
        {
            Edgenode* pre(p);
            p = p->getlink();
            while(p!=nullptr)
            {
                if(p->getveradj()==v2)
                {
                    q = p->getlink();
                    delete p;
                    pre->setlink(q);
                    p = q;
                    break;
                }
                else
                {
                    p = p->getlink();
                    pre = pre->getlink();
                }
            }
        }
        /***********************************************/
        //����ͼ��˫����
        Edgenode* p1(nullptr);
        Edgenode* q1(nullptr);
        p1 = vertexlist[v2].getadjacent();
        if(p1->getveradj()==v1)
        {
            q1 = p1->getlink();
            delete p1;
            vertexlist[v1].setadjacent(q1);
            return true;
        }
        Edgenode* pre1(p1);
        p1 = p1->getlink();
        while(p1!=nullptr)
        {
            if(p1->getveradj()==v1)
            {
                q1 = p1->getlink();
                delete p1;
                pre1->setlink(q1);
                p1 = q1;
                return true;
            }
            else
            {
                p1 = p1->getlink();
                pre1 = pre1->getlink();
            }
        }
        return false;
    }
    int getweight(const int& v1,const int& v2)
    {
        if(v1==v2||v1<0||v2<0||v1>graphsize||v2>graphsize)
        {
            cout << "��������!" << endl;
            return -1;
        }
        Edgenode* p = vertexlist[v1].getadjacent();
        while(p!=nullptr)        //ѭ�������˱�
        {
            if(p->getveradj()==v2)
                return p->getweight();
            p = p->getlink();
        }
        cout << "�˱߲�����" << endl;
        return -1;                //�˱߲�����
    }
    int findFirstadj(const int& v)
    {
        if(v<0||v>graphsize)
        {
            cout << "��������!" << endl;
            return -1;
        }
        Edgenode* p(nullptr);
        p = vertexlist[v].getadjacent();
        if(p!=nullptr)
            return p->getveradj();
        else
        {
            /*cout << "�˱߲������ڽӶ���" << endl;*/
            return -1;
        }
    }
    int findFirstadj(const int& v1,const int& v2)
    {
        if(v1<0||v2<0||v1>graphsize||v2>graphsize)
            return -1;
        Edgenode* p = vertexlist[v1].getadjacent();
        while(p->getveradj()!=v2 && p!=nullptr)
            p = p->getlink();
        if(p==nullptr)
            return -1;
        p = p->getlink();
        if(p==nullptr)
            return -1;
        return p->getveradj();
    }
    void depthFirstTraverse(const int& v) //�ǵݹ�������ȱ���
    {
        int* visited(nullptr);
        visited = new int[graphsize];
        for(int i=0;i<graphsize;++i)
            visited[i] = 0;
        stack<int> astack;
        astack.push(v);
        int w(0);
        int k(0);
        while(!astack.empty())
        {
            w = astack.top();
            astack.pop();
            visited[w] = 1;
            cout << w << " ";
            k = findFirstadj(w);
            while(k!=-1)
            {
                if(visited[k]==0)
                    astack.push(k);
                k = findFirstadj(w,k);
            }
        }
        delete[] visited;
    }
    void broadFirstTraverse(const int& s)    //�ǵݹ������ȱ���
    {
        int* visited(nullptr);
        visited = new int[graphsize];
        for(int k=0;k<graphsize;++k)
            visited[k] = 0;
        cout << s << " ";
        visited[s] = 1;
        queue<int> aqueue;
        aqueue.push(s);
        int v(0);
        int w(0);
        while(!aqueue.empty())
        {
            v = aqueue.front();
            aqueue.pop();
            w = findFirstadj(v);
            while(w!=-1)
            {
                if(visited[w]==0)
                {
                    cout << w << " ";
                    visited[w] = 1;
                    aqueue.push(w);
                }
                w = findFirstadj(v,w);
            }
        }
        delete []visited;
    }
};
#endif // GRAPH_H

