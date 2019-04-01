#ifndef TREE_H
#define TREE_H
#include "Treenode.h"
#include "IterateLastOrderNode.h"   //��������������������
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class Tree
{
private:
    Treenode<T>* root;
public:
    Tree(Treenode<T>* temproot=nullptr):root(temproot) {}
    ~Tree() { cleartree(); }
    void setroot(Treenode<T>* temproot) { root = temproot; }
    Treenode<T>* getroot() { return root; }
    void createtree()     //ʹ�ø���������������(��ȷ)
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
        temproot = new Treenode<T>(data);
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
    }
    void cleartree()
    {
        if(getroot()==nullptr)
            return;
        deleteSubtree(getroot());
        setroot(nullptr);
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
    /*void createtree() //�ù���������ķ�ʽ����������(�Ǵ����)
    {
        cout << "please input the data of root node:" << endl;
        int rootdata(0);
        cin >> rootdata;
        setroot(new Treenode<T>(rootdata));
        createSubtree(root);
    }
    void createSubtree(Treenode<T>* t)   //������tΪ��������
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
    void levelOrder(Treenode<T>* temproot)const     //��α���
    {
        queue<int> aqueue;
        if(temproot!=nullptr)
        {
            Treenode<T>* tempptr(nullptr);
            aqueue.push(temproot);
            while(!aqueue.empty())
            {
                tempptr = aqueue.front();
                aqueue.pop();
                cout << tempptr->getdata() << endl;
                tempptr = tempptr->getfirstchild();
                while(tempptr!=nullptr)
                {
                    aqueue.push(tempptr);
                    tempptr = tempptr->getnextbrother();
                }
            }
        }
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
#endif // TREE_H
