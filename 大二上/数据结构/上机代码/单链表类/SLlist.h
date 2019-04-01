#ifndef SLLIST_H
#define SLLIST_H
#include <iostream>
using namespace std;
#include "SLnode.h"
template <class T>
class SLlist
{
private:
    SLnode<T>* head;
    SLnode<T>* tail;
    SLnode<T>* current;
    int length;
public:
    void print()    //����������,��ʽ����Ӧע�͵�
    {
        SLnode<T>* temp(head);
        for(int i=0;i<length;++i)
        {
            cout << temp->data;
            temp = temp->next;
        }
    }
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
    void create(int k,T* a);
    void insertBehind(const T& item);
    void insertInHead(const T& item);
    void insertInTail(const T& item);
    bool deleteBehind();
    bool deleteHead();
    bool deleteTail();
    bool storeInCur(const T& item);
    bool storeInK(int k,const T& item);
    T getCurdata() const;
    T getK(int k) const;
    int findx(const T& x);
    bool moveCurToNext();
    bool moveCurToHead();
};
template <class T>
void SLlist<T>::create(int k,T* a)
{
    SLnode<T>* temp(NULL);
    SLnode<T>* prev(NULL);
    for(int i=0;i<k;++i)
    {
        temp = new SLnode<T>(a[i],NULL);
        length++;
        if(head==NULL)          //������һ���ڵ㶼û�У���ʱҪ����head��tail
        {
            head = temp;
            prev = head;
            current = head;
            tail = head;
        }
        else
        {
            prev->next = temp;
            prev = temp;
            tail = temp;
        }
    }
}
template <class T>
void SLlist<T>::insertBehind(const T& item)   //������һ���ɹ���
{
    SLnode<T>* temp=NULL;
    temp = new SLnode<T>(item,current->next);
    current->next = temp;
    length++;
    if(tail==head)      //��ʱҪ����β�ڵ�����
    {
        tail = temp;
    }
}
template <class T>
void SLlist<T>::insertInHead(const T& item)
{
    SLnode<T>* temp(NULL);
    temp = new SLnode<T>(item,head);
    head = temp;
    length++;               //��һ��ʼhead��Ϊ�գ����ʱ�������ٶ�tail
    if(tail==NULL)
        tail = head;
}
template <class T>
void SLlist<T>::insertInTail(const T& item)
{
    SLnode<T>* temp(NULL);
    temp = new SLnode<T>(item,NULL);
    if(tail==NULL)
    {
        tail = head = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
    length++;
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
bool SLlist<T>::storeInCur(const T& item)
{
    if(current==NULL)
        return false;
    current->data = item;
    return true;
}
template <class T>
bool SLlist<T>::storeInK(int k,const T& item)
{
    if(k==0||k>length)
        return false;
    SLnode<T>* temp(head);
    for(int i=0;i<k;++i)
    {
        temp = temp->next;
    }
    temp->data = item;
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
T SLlist<T>::getK(int k) const
{
    if(k==0||k>length)
        return T(-1);
    SLnode<T>* temp(head);
    for(int i=1;i<k;++i)
    {
        temp = temp->next;
    }
    return temp->data;
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
