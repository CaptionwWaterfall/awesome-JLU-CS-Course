#include <iostream>
#include "UFset.h"
using namespace std;

int main()
{
    UnionFindset aset;
    cout << "������Ԫ�ظ���:" << endl;
    int setnumbers(0);
    cin >> setnumbers;
    cout << "����������Ԫ��:" << endl;
    aset.create(setnumbers);
    return 0;
}
