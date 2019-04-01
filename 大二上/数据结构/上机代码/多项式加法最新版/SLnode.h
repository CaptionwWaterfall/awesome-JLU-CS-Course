#ifndef SLNODE_H
#define SLNODE_H
#include <iostream>
template <class T>
class SLnode
{
public:
    T data;    //data��Ϊϵ��,exp��Ϊָ��
    T exp;
    SLnode<T>* next;
    SLnode(SLnode* nextnode=NULL):next(nextnode) {}
    SLnode(const T& item,const T& expitem,SLnode* nextnode=NULL):data(item),exp(expitem),next(nextnode) {}
};
#endif // SLNODE_H
