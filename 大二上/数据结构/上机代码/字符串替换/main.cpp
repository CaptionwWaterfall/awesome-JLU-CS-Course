#include <iostream>
#include <string>
using namespace std;
void getNext(string& s,int next[]);
int KMPmatch(string& text,string& pattern);
int main()
{
    string str1;
    string str2;
    string str3;
    cout << "please input str1:" << endl;
    getline(cin,str1);
    cout << "please input str2:" << endl;
    getline(cin,str2);
    cout << "please input str3:" << endl;
    getline(cin,str3);
    const int n = KMPmatch(str1,str2);
    if(n!=-1)
    {
        cout << "str2 is the substring of str1." << endl;
        str1.erase(n,str2.length());
        str1.insert(n,str3);
    }
    else
    {
        cout << "str2 isn't the substring of str1." << endl;
        //��str3���洮temp
        string temp;
        temp.resize(str3.length());
        for(int i=0,j=str3.length()-1;i<str3.length();++i,--j)
        {
            temp[i] = str3[j];
        }
        int j(0);
        j = str1.length()-temp.length();
        str1.erase(j,temp.length());
        str1 += temp;
    }
    cout << "the result is:" << endl;
    cout << str1;
    return 0;
}
void getNext(string& s,int next[])  //���next���飺next[i]�ĺ����ǵ�ģʽ��p��i+1λƥ��ʧ��ʱ
{                                   //iӦ���˻ص������λ��(�Դ�ͳKMP�㷨������΢�Ľ�)
    int j(-1);
    next[0] = -1;
    for(int i=1;i<s.length();++i)  //���next[1]--next[s.length()-1]
    {
        while(j!=-1 && s[i]!=s[j+1])
        {
            j = next[j];  //j������ֵ��next[j],ֱ��s[i]==s[j+1]����j�˻ص�-1
        }
        if(s[i]==s[j+1])
            j++;          //��jָ��ԭnext[i]��λ��
        //�Դ�ͳKMP�ĸĽ�֮�������¿�ʼ
        if(j==-1 || s[i+1]!=s[j+1])
            next[i] = j;
        else              //s[i+1]==s[j+1]��ζ�Ż���һ����ʵ����
        {
            next[i] = next[j];   //next[i]ֱ�Ӽ̳���next[j],��ʡ��һ��û��Ҫ�Ļ���
        }
    }
}
int KMPmatch(string& text,string& pattern)
{
    int next[pattern.length()];
    getNext(pattern,next);            //����pattern��next����
    int j=-1;
    for(int i=0;i<text.length();++i)  //��ͼƥ��next[i]
    {
        while(j!=-1 && text[i]!=pattern[j+1])
        {
            j=next[j];
        }
        if(text[i]==pattern[j+1])
        {
            j++;
        }
        if(j==pattern.length()-1)         //pattern��ȫƥ�䣬����ƥ��ģʽ�������ַ��±�
        {
            return i-j;
        }
    }
    return -1;     //ƥ��ʧ��
}
