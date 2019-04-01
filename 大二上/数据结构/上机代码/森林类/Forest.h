#ifndef FOREST_H
#define FOREST_H
#include "Treenode.h"
#include "IterateLastOrderNode.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <typename T>
class Forest
{
private:
    Treenode<T>** treespoint;  //ָ������,ÿ������Ԫ�ش��һ��������ָ��
    int treescount;
public:
    Forest(Treenode<T>** temptreespoint=nullptr,int temptreescount=0):
        treespoint(temptreespoint),treescount(temptreescount)  {}
    ~Forest() { clearforest(); }
    void createforest()
    {
        cout << "please input the number of trees in this forest:" << endl;
        cin >> treescount;
        treespoint = new Treenode<T>*[treescount];
        for(int i=0;i<treescount;++i)
            createtree(i);
    }
    void createtree(int position)
    {
        queue<Treenode<T>*> aqueue;
        cout << "�Ƿ��ǿ���? ����������0,��������1." << endl;
        int flag(1);
        cin >> flag;
        if(flag==0)
            return;
        cout << "�������:" << endl;
        int data(0);       //��ŵ�ǰ�ڵ�ֵ
        int numbers(0);    //��ŵ�ǰ�ڵ��ӽڵ����
        Treenode<T>* temproot(nullptr);
        Treenode<T>* tempsub(nullptr);
        treespoint[position] = temproot = new Treenode<T>(data);
        aqueue.push(temproot);
        while(!aqueue.empty())
        {
            temproot = aqueue.front();
            aqueue.pop();
            cout << "�����뵱ǰ�ڵ���ӽڵ����:" << endl;
            cin >> numbers;
            for(int i=0;i<numbers;++i)
            {
                cout << "�������ӽڵ�ֵ:" << endl;
                cin >> data;
                tempsub = new Treenode<T>(data);
                if(i==0) //����
                {
                    temproot->setfirstchild(tempsub);
                    temproot = tempsub;
                }
                else
                {
                    temproot->setnextbrother(tempsub);
                    temproot = tempsub;
                }
                aqueue.push(tempsub);
            }
        }
        /*cout << "please input the rootdata of this tree:" <<endl;
        int rootdata(0);
        cin >> rootdata;
        treespoint[i] = new Treenode(rootdata);
        createSubtree(treespoint[i]);*/
    }
    /*void createSubtree(Treenode<T>* t)   //������tΪ��������
    {
        int n(0);
        int value(0);
        cout << "please input subnode numbers of current node:" << endl;
        cin >> n;                        //n���浱ǰ�ڵ��ӽڵ����
        Treenode<T>* bigchild(nullptr);  //����
        Treenode<T>* prechild(nullptr);  //thischild�ĸ���
        Treenode<T>* thischild(nullptr);
        for(int i=1;i<=n;++i)
        {
            cout << "�������"<<i<<"���ӽڵ��ֵ" << endl;
            cin >> value;
            if(i==1)           //˵���Ǵ��ӽڵ�
            {
                bigchild = new Treenode<T>(value);
                t->setfirstchild(bigchild);
                createSubtree(bigchild);
                prechild = bigchild;
            }
            else              //�Ǵ��ӽ��
            {
                thischild = new Treenode<T>(value);
                prechild->setnextbrother(thischild);
                prechild = thischild;
                createSubtree(thischild);
            }
        }
    }*/
    void clearforest()
    {
        for(int i=0;i<treescount;++i)
        {
            deleteSubtree(treespoint[i]);
            treespoint[i] = nullptr;
        }
        treescount = 0;
        delete []treespoint;
    }
    void deleteSubtree(Treenode<T>* p)
    {
        if(p!=nullptr)
        {
            Treenode<T>* q(nullptr);
            q = p->getfirstchild();
            Treenode<T>* next(nullptr);
            while(q!=nullptr)
            {
                next = q->getnextbrother();
                deleteSubtree(q);
                q = next;
            }
            delete p;
        }
    }
    void RPOforest()           //�ݹ��ȸ�����ɭ��
    {
        for(int i=0;i<treescount;++i)
        {
            recurPreOrder(treespoint[i]);
        }
    }
    void IPOforest()          //�����ȸ�����ɭ��
    {
        for(int i=0;i<treescount;++i)
        {
            iteratePreOrder(treespoint[i]);
        }
    }
    void LOforest()           //��α���ɭ��
    {
        queue<Treenode<T>*> aqueue;
        for(int i=0;i<treescount;++i)
        {
            cout << treespoint[i]->getdata();
            aqueue.push(treespoint[i]);
        }
        Treenode<T>* p(nullptr);
        Treenode<T>* q(nullptr);
        while(!aqueue.empty())
        {
            p = aqueue.front();
            aqueue.pop();
            if(p->getfirstchild()!=nullptr)
            {
                q = p->getfirstchild();
                while(q!=nullptr)
                {
                    cout << q->getdata();
                    aqueue.push(q);
                    q = q->getnextbrother();
                }
            }
        }
    }
    void RLOforest()          //�ݹ�������ɭ��
    {
        for(int i=0;i<treescount;++i)
        {
            recurLastOrder(treespoint[i]);
        }
    }
    void ILOforest()         //�����������ɭ��
    {
        for(int i=0;i<treescount;++i)
        {
            iterateLastOrder(treespoint[i]);
        }
    }
    //����������ԭ�����
    void recurPreOrder(Treenode<T>* temproot)const  //�ݹ��ȸ�����
    {
        if(temproot!=nullptr)
        {
            cout << temproot->getdata() << endl;
            Treenode<T>* childtree(nullptr);
            childtree = temproot->getfirstchild();
            while(childtree!=nullptr)
            {
                recurPreorder(childtree);
                childtree = childtree->getnextbrother();
            }
        }
    }
    void iteratePreOrder(Treenode<T>* temproot)const //�����ȸ�����
    {
        if(temproot==nullptr)
            return;
        stack<int> astack;
        Treenode<T>* tempptr(nullptr);
        do
        {
            while(tempptr!=nullptr)
            {
                cout << tempptr->getdata() <<endl;
                astack.push(tempptr);
                tempptr = tempptr->getfirstchild();
            }
            while(tempptr==nullptr && !astack.empty())
            {
                astack.pop(tempptr);
                tempptr = tempptr->getnextbrother();
            }
        }while(!astack.empty());
    }

    void recurLastOrder(Treenode<T>* temproot)const  //�ݹ�������
    {
        if(temproot!=nullptr)
        {
            Treenode<T>* thechild(nullptr);
            thechild = temproot->getfirstchild();
            while(thechild!=nullptr)
            {
                recurLastOrder(thechild);
                thechild = thechild->getnextbrother();
            }
            cout << thechild->getdata() <<endl;
        }
    }
    void iterateLastOrder(Treenode<T>* temproot)  //�����������
    {
        if(temproot==nullptr)
            return;
        stack<IterateLastOrderNode*> astack;    //��������ջ
        IterateLastOrderNode* curAssisNode(nullptr);
        IterateLastOrderNode* leftAssisNode(nullptr);
        IterateLastOrderNode* rightAssisNode(nullptr);
        curAssisNode = new IterateLastOrderNode;
        curAssisNode->setptr(temproot);
        curAssisNode->setflag(0);
        astack.push(curAssisNode);
        int i=0;
        while(!astack.empty())
        {
            curAssisNode = astack.top();
            temproot = curAssisNode->getptr();
            i = curAssisNode->getflag();
            if(i==0)           //˵����δ�����κ�������׼������������
            {
                curAssisNode->setflag(1);
                astack.push(curAssisNode);
                if((temproot->getfirstchild())!=nullptr)
                {
                    leftAssisNode = new IterateLastOrderNode(temproot->getfirstchild(),0);
                    leftAssisNode->setflag(0);
                    astack.push(leftAssisNode);
                }
            }
            if(i==1)           //�ѱ�������������׼������������
            {
                curAssisNode->setflag(2);
                astack.push(curAssisNode);
                if((temproot->getnextbrother())!=nullptr)
                {
                    rightAssisNode = new IterateLastOrderNode(temproot->getnextbrother(),0);
                    rightAssisNode->setflag(0);
                    astack.push(rightAssisNode);
                }
            }
            if(i==2)           //temproot��ָ�������������������꣬���ʸýڵ㱾��
                cout << temproot->getdata() << endl;
        }
    }
};
#endif // FOREST_H
