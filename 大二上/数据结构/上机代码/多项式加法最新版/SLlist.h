//SLlist.h
#ifndef SLLIST_H
#define SLLIST_H
#include <iostream>
#include "SLnode.h"
using namespace std;
template <class T>
class SLlist
{
private:
    SLnode<T>* head;
    SLnode<T>* tail;
    SLnode<T>* current;
    int length;
public:
    SLlist(SLnode<T>* ahead=NULL,SLnode<T>* atail=NULL,SLnode<T>*acurrent=NULL
     ,int alenth=0):head(ahead),tail(atail),current(acurrent),length(alenth) {}
    ~SLlist()
    {
        if(head != NULL)   //����ʱ�����ѿգ��򲻱����˹�����
        {
            if(head->next==NULL)   //ֻ��һ���ڵ�
            {
                delete head;
                tail = head = current = NULL;
            }
            else
            {
                while(head==NULL)
                {
                    tail = head->next;
                    delete head;
                    head = tail;
                }
                current = NULL;
            }
        }
    }
    void create(int tempcoef,int tempexp);   //���е���Ӳ�����ί����create����
    SLnode<T>* add(SLlist<T>& another);
    bool deleteBehind();
    bool deleteHead();
    bool deleteTail();
    T getCurdata() const;
    int findx(const T& x);
    bool moveCurToNext();
    bool moveCurToHead();
};
template <class T>
void SLlist<T>::create(int tempcoef,int tempexp)
{
    SLnode<T>* temp(NULL);
    temp = new SLnode<T>(tempcoef,tempexp);
    length++;
    if(head==NULL)     //����ǿձ�
    {
        head = temp;
        current = head;
        tail = head;
    }
    else
    {
        SLnode<T>* ptr(head);
        while(ptr!=NULL)
        {
            if(head->exp < temp->exp)    //�����ͷ��㶼��
            {
                temp->next = head;
                head = temp;
                break;
            }
            if(ptr->exp==temp->exp)      //(��ͷ���Сǰ����)��ָ����ȣ���ϵ����Ӽ���
            {
                ptr->data += temp->data;
                delete temp;
                temp =NULL;
                break;
            }
            if(temp->exp < ptr->exp)
            {
                if(ptr->next==NULL)      //˵��temp��ʱ����С���Ǹ�
                {
                    ptr->next = temp;
                    tail = temp;
                    break;
                }
                else
                {
                    if(temp->exp > ptr->next->exp)   //�����ǰһ��С���Ⱥ�һ�����ô�Ͳ�����
                    {
                        temp->next = ptr->next;
                        ptr->next = temp;
                        break;
                    }
                }
            }
            ptr = ptr->next;
        }
    }
}
template <class T>
SLnode<T>* SLlist<T>::add(SLlist<T>& another)
{
    SLnode<T>* pra(head);
    SLnode<T>* prb(another.head);
    SLnode<T>* chead(NULL);
    SLnode<T>* temp(NULL);
    while(pra!=NULL && prb!=NULL)
    {
        if(pra->exp==prb->exp)
        {
            if(pra->data+prb->data==0)
            {
                pra = pra->next;
                prb = prb->next;
            }
            else
            {
                if(chead==NULL)
                {
                    chead = new SLnode<T>(pra->data+prb->data,pra->exp);
                    temp = chead;
                }
                else
                {
                    temp->next = new SLnode<T>(pra->data+prb->data,pra->exp);
                    temp = temp->next;
                }
                pra = pra->next;
                prb = prb->next;
            }

        }
         else if(pra->exp < prb->exp)
        {
            if(chead==NULL)
            {
                chead = new SLnode<T>(prb->data,prb->exp);
                temp = chead;
            }
            else
            {
                temp->next = new SLnode<T>(prb->data,prb->exp);
                temp = temp->next;
            }
            prb = prb->next;
        }
        else if(pra->exp > prb->exp)
        {
            if(chead==NULL)
            {
                chead = new SLnode<T>(pra->data,pra->exp);
                temp = chead;
            }
            else
            {
                temp->next = new SLnode<T>(pra->data,pra->exp);
                temp = temp->next;
            }
            pra = pra->next;
        }
    }
    //��ʱ��ʣ�µ��Ǹ���������������нڵ㸴�Ƶ�chead��
    while(prb!=NULL)
    {
        temp->next = new SLnode<T>(prb->data,prb->exp);
        temp = temp->next;
        prb = prb->next;
    }
    while(pra!=NULL)
    {
        temp->next = new SLnode<T>(pra->data,pra->exp);
        temp = temp->next;
        pra = pra->next;
    }
    return chead;
}

template <class T>
bool SLlist<T>::deleteBehind()
{
    if(current->next==NULL || head==NULL)
        return false;
    SLnode<T>* temp(NULL);
    temp = current->next->next;
    delete current->next;
    current->next = temp;
    if(temp==NULL)        //˵��currentָ����ǵ����ڶ����ڵ�,��ʱҪ��β�ڵ�
        tail = current;
    length--;
    return true;
}
template <class T>
bool SLlist<T>::deleteHead()
{
    if(head==NULL)
        return false;
    if(head==tail)         //˵����ʱֻ��һ���ڵ�
    {
        delete head;
        head = tail = current = NULL;
        length--;
        return true;
    }
    //������һ���ڵ�
    SLnode<T>* temp(NULL);
    temp = head->next;
    delete head;
    head = temp;
    length--;
    return true;
}
template <class T>
bool SLlist<T>::deleteTail()
{
    if(tail==NULL)
        return false;
    if(head==tail)         //˵����ʱֻ��һ���ڵ�
    {
        delete tail;
        head = tail = current = NULL;
        length--;
        return true;
    }
    SLnode<T>* temp(head);
    while(temp->next!=tail)   //�ƶ�temp��ָ���������ڶ����ڵ�
    {
        temp = temp->next;
    }
    delete tail;
    temp->next = NULL;
    tail = temp;
    length--;
    return true;
}
template <class T>
T SLlist<T>::getCurdata() const
{
    if(current==NULL)
        return false;
    return current->data;
}
template <class T>
int SLlist<T>::findx(const T& x) //Ĭ��ֻ��һ���ڵ��ֵΪx
{                                //���ж���ڵ�:�����������һ�飬��ֵΪx��Ԫ��
    SLnode<T>* temp(head);       //���Ƶ�һ���������У������������
    int i(1);
    for(i=1;i<=length;++i)
    {
        if(temp->data==x)
        {
            break;
        }
        if(temp->next==NULL)     //���iΪ0�������ʧ��
        {
            i=0;
            break;
        }
        temp = temp->next;
    }
    return i;
}
template <class T>
bool SLlist<T>::moveCurToNext()
{
    if(current == NULL)
        return false;
    current = current->next;
    return true;
}
template <class T>
bool SLlist<T>::moveCurToHead()
{
    current = head;
    return true;
}

#endif // SLLIST_H
