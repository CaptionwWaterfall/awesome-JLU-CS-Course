//??
#include "Comparator.h"                                    //比较器抽象类 
#include "TriElement.h"                                    //二叉树的静态三叉链表元素

//TriElement对象比较器类，提供TriElement类两个对象按value比较大小的规则，继承Comparator<T>比较器抽象类 
//用于构造Huffman树时比较大小
class TriElementComparator : public Comparator<TriElement>
{
  public: 
    int compare(TriElement e1, TriElement e2)                      //覆盖基类的纯虚函数
    {
        return (e1.parent==-1 && e1.data < e2.data;  
    }
};
HuffmanTree::HuffmanTree(int weight[], int n) : huftree(2*n-1) 
{
    for (int i=0; i<n; i++)                                //初始化
    {   this->charset.insert(i,'A'+i);                     //默认字符集从'A'开始的n个字符
        this->huftree.insert(TriElement(weight[i],-1,-1,-1)); //初始有n个叶子结点
    }

    for (int i=0; i<n-1; i++)                              //构造n-1个2度结点，每次循环构造1个2度结点
    {
        int min1=0, min2=0;//, x1, x2;
        while (min1<n+i && huftree[min1].parent!=-1)
            min1++;
        min2=min1;//, x1, x2;
        //min1 = min2 = 0x7fffffff;                          //选择最小和次最小权值，初值为整数最大值（16进制）
        //int x1=0, x2=0;                                      //记录两个无父母的最小权值结点下标
        for (int j=0; j<n+i; j++)                          //查找两个无父母的最小权值结点
            if (huftree[j].parent==-1 && huftree[j]<huftree[min1])//执行TriElement的<
            {
                min2 = min1;
//                x2 = x1;
                min1 = j;//huftree[j].data;                    //min1记下最小权值
//                x1 = j;                                    //x1记下最小权值结点的下标
            }
            else if (huftree[j].parent==-1 && huftree[j]<huftree[min2])
                 {
                     min2 = j;//huftree[j].data;               //min2记下次小权值
 //                    x2 = j;                               //x2记下次小权值结点的下标
                 }

        huftree[min1].parent = n+i;                          //将找出的两棵权值最小的子树合并为一棵子树
        huftree[min2].parent = n+i;        
        huftree.insert(TriElement(huftree[min1].data+huftree[min2].data, -1, min1, min2));   //添加第n+i个结点
    }
    cout<<"Huffman树的结点顺序表："<<this->huftree;
}

/*
void min(T values[], int n, int &min1, int &min2)	//求values数组的最小值和次最小值
{
         int min1=0, min2=0;//, x1, x2;
        while (min1<huftree[min1]
            min1++;
           int min1=0, min2=0, x1, x2;
        //min1 = min2 = 0x7fffffff;                          //选择最小和次最小权值，初值为整数最大值（16进制）
        //int x1=0, x2=0;                                      //记录两个无父母的最小权值结点下标
        for (int j=0; j<n+i; j++)                          //查找两个无父母的最小权值结点
            if (huftree[j].parent==-1 && huftree[j]<huftree[min1])//执行TriElement的<
            {
                min2 = min1;
//                x2 = x1;
                min1 = j;//huftree[j].data;                    //min1记下最小权值
//                x1 = j;                                    //x1记下最小权值结点的下标
            }
            else if (huftree[j].parent==-1 && huftree[j]<huftree[min2])
                 {
                     min2 = j;//huftree[j].data;               //min2记下次小权值
 //                    x2 = j;                               //x2记下次小权值结点的下标
                 }

}*/

//第10章？？10.2
9.  比较器
1-1  Huffman算法树的结点，每次选择两棵最小权值的树合并。
调用求最小值函数？？比较器
void min(T values[], int n, T &min1, T &min2)	//求values数组的最小值和次最小值
（2） 比较器抽象类
比较器抽象类Comparator声明如下，声明compare(T,T)纯虚函数，为T类的两个对象提供比较大小的规则，该纯虚函数由子类实现，表现为运行时覆盖。
template <class T>
class Comparator                               	//比较器抽象类
{
  public:
     virtual int compare(T obj1, T obj2)=0;   //提供T类的两个对象比较大小的规则，纯虚函数
};

