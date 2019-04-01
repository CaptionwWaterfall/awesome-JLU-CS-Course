#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
#include <windows.h>
#include "Student.h"
#include "StudentStuct.h"
#include "Search.h"
#include "Sort.h"
using namespace std;

class StudentList
{
private:
    Student* head;//ͷָ��
    Student* tail;//βָ��
    int studentcount;//ѧ������������
    string f;//�ļ�·���ַ���
    bool flag;
    //�ɼ����ݸ�������
    int allscore[10];
    int maxscore[10];
    int minscore[10];
    int averscore[10];
public:
    StudentList(Student* temphead=nullptr,Student* temptail=nullptr,int tempcount=0,string tf="studentmessage.txt",bool tflag=false)
                      :head(temphead),tail(temptail),studentcount(tempcount),f(tf),flag(tflag)
    {
        for(int m=0;m<10;++m)
        {
            allscore[m] = 0;
            maxscore[m] = 0;
            minscore[m] = 0;
            averscore[m] = 0;
        }
    }
    ~StudentList() { clearList(); }
    /****************************************************************/
    Student* gethead() { return head; }
    void sethead(Student* ahead) { head = ahead; }
    int getstudentcount() { return studentcount; }
    /********************************��ӡƽ���ɼ�********************************/
    void displayaverscore()
    {
        system("cls");
        cout << "��ǰ���и���ƽ����Ϊ:  "<<endl;
        for(int m=0;m<10;++m)
            cout << "��Ŀ" << m+1 << "��" << averscore[m] << endl;
        cout << endl;
        system("pause");
    }
    void displayaverscore(int k)
    {
        system("cls");
        cout << "�ÿ�Ŀƽ����Ϊ:  " << averscore[k] << endl;
        system("pause");
    }
    /*******************************��ӡ��ͷ�*********************************/
    void displayminscore()
    {
        system("cls");
        cout << "��ǰ���и�����ͷ�Ϊ:  "<<endl;;
        for(int m=0;m<10;++m)
            cout << "��Ŀ" << m+1 << "��" << minscore[m] << endl;
        cout << endl;
        system("pause");
    }
    void displayminscore(int k)
    {
        system("cls");
        cout << "�ÿ�Ŀ��ͷ�Ϊ:  " << minscore[k] << endl;
        system("pause");
    }
    /*******************************��ӡ��߷�*********************************/
    void displaymaxscore()
    {
        system("cls");
        cout << "��ǰ���и�����߷�Ϊ:  "<<endl;
        for(int m=0;m<10;++m)
            cout << "��Ŀ" << m+1 << "��" << maxscore[m] << endl;
        cout << endl;
        system("pause");
    }
    void displaymaxscore(int k)
    {
        system("cls");
        cout << "�ÿ�Ŀ��߷�Ϊ:  " << maxscore[k] << endl;
        system("pause");
    }
    /*********************************�������*******************************/
    void clearList()
    {
        Student* current(head);
        while(head!=nullptr)//delete
        {
            head = head->getnext();
            delete current;
            current = head;
        }
        head = nullptr;
        current = nullptr;
        tail = nullptr;
        studentcount = 0;
        for(int m=0;m<10;++m)
        {
            minscore[m] = 0;
            maxscore[m] = 0;
            allscore[m] = 0;
        }
    }
    /*********************************�޸�ѧ����Ϣ*******************************/
    void changemessage()
    {
        system("cls");
        cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�" << endl;
        int tempID(0);
        cin >> tempID;
        //���Ҹý��
        Student* tempp(head);
        int acount(0);
        for(int j=0;j<studentcount;++j)
        {
            if(tempp->getstudentID()==tempID)
                break;
            acount++;
            tempp = tempp->getnext();
        }
        int k(acount);
        Student* current(nullptr);
        //�ƶ�current��ָ��λ��
        if(k>studentcount/2)
        {
            current = tail;
            for(int i=studentcount-1;i>k;--i)
                current = current->getprev();
        }
        if(k<=studentcount/2)
        {
            current = head;
            for(int i=0;i<k;++i)
                current = current->getnext();
        }
        cout << "ѧ��ÿ�˹̶�,���ɸ���. �밴������ʾ�ظ���" << endl;
        cout << "�ظ�1: �޸�ѧ������" << endl;
        cout << "�ظ�2: �޸Ŀ�Ŀ�ɼ�" << endl;
        string stra;
        cin >> stra;
        while(stra!="1"&&stra!="2")
        {
            cout << "�ظ���ʽ�����밴������ʾ�ظ���" << endl;
            cout << "�ظ�1: �޸�ѧ������" << endl;
            cout << "�ظ�2: �޸Ŀ�Ŀ�ɼ�" << endl;
        }
        if(stra=="1")
        {
            cout << "�������µ�ѧ��������";
            string temps;
            cin >> temps;
            current->setname(temps);
            cout << "�޸����." << endl;
        }
        if(stra=="2")
        {
            string aflag("1");
            int number1(0);
            while(aflag=="1")
            {
                cout << "��Ŀ���0-9,��������Ҫ�޸ĵĿ�Ŀ���: ";
                cin >> number1;
                while(number1<0||number1>9)
                {
                    cout << "����������,����������: ";
                    cin >> number1;
                }
                cout << "������ÿ�Ŀ�³ɼ�(0-100):" << endl;
                int number2(0);
                cin >> number2;
                while(number2<0||number2>100)
                {
                    cout << "�ɼ��������,����������(0-100): ";
                    cin >> number2;
                }
                for(int m=0;m<10;++m)
                   allscore[m] -= current->getsubject()[m];
                current->getsubject()[number1] = number2;
                for(int m=0;m<10;++m)
                   allscore[m] += current->getsubject()[m];
                for(int m=0;m<10;++m)
                   averscore[m] = allscore[m] / studentcount;
                traverse_getmaxmin();
                cout << "�����޸�������Ŀ�ɼ���ظ�1,����ظ�����" << endl;
                cin >> aflag;
            }
        }
        this->outFileInOrder(f);
        system("pause");
    }
    /*********************************���ߺ���*******************************/
    void traverse_getmaxmin()   //������������߷ֺ���ͷ�(����ɾ��������ʹ��)
    {
        for(int m=0;m<10;++m)
        {
            maxscore[m] = head->getsubject()[m];
            minscore[m] = head->getsubject()[m];
        }
        Student* tempp(head->getnext());
        while(tempp!=nullptr)
        {
            for(int m=0;m<10;++m)
            {
                if(tempp->getsubject()[m] < minscore[m])
                    minscore[m] = tempp->getsubject()[m];
                if(tempp->getsubject()[m] > maxscore[m])
                    maxscore[m] = tempp->getsubject()[m];
            }
            tempp = tempp->getnext();
        }
    }
    /********************************ɾ��ѧ����Ϣ********************************/
    void deletestudent()
    {
        system("cls");
        cout << "������Ҫɾ����ѧ��ѧ�ţ�" << endl;
        int tempID(0);
        cin >> tempID;
        //���Ҹý��
        Student* tempp(head);
        int acount(0);
        for(int j=0;j<studentcount;++j)
        {
            if(tempp->getstudentID()==tempID)
                break;
            acount++;
            tempp = tempp->getnext();
        }
        int k(acount);
        Student* current(nullptr);
        //�ƶ�current��ָ��λ��
        if(k==0)
        {
            current = head;
            head = head->getnext();
            head->setprev(nullptr);
            for(int m=0;m<10;++m)
                allscore[m] -= current->getsubject()[m];
            delete current;
            studentcount--;
            for(int m=0;m<10;++m)
                averscore[m] = allscore[m] / studentcount;
            traverse_getmaxmin();
            return;
        }
        if(k==(studentcount-1))
        {
            current = tail;
            tail = tail->getprev();
            tail->setnext(nullptr);
            for(int m=0;m<10;++m)
                allscore[m] -= current->getsubject()[m];
            delete current;
            studentcount--;
            for(int m=0;m<10;++m)
                averscore[m] = allscore[m] / studentcount;
            traverse_getmaxmin();
            return;
        }
        if(k>studentcount/2)
        {
            current = tail;
            for(int i=studentcount-1;i>k;--i)
                current = current->getprev();
        }
        if(k<=studentcount/2)
        {
            current = head;
            for(int i=0;i<k;++i)
                current = current->getnext();
        }
        //�ж�k
        current->getprev()->setnext(current->getnext());
        current->getnext()->setprev(current->getprev());
        for(int m=0;m<10;++m)
                allscore[m] -= current->getsubject()[m];
        delete current;
        studentcount--;
        for(int m=0;m<10;++m)
                averscore[m] = allscore[m] / studentcount;
        traverse_getmaxmin();
        this->outFileInOrder(f);
        system("pause");
    }
    /*******************************����ѧ����Ϣ�����ý���ʽ���뺯����*********************************/
    void insertstudent()
    {
        interaction();
    }
    /*******************************����д���ļ�*********************************/
    void outFileInOrder(const string& str)
    {
        ofstream outfile(str);
        Student* current(head);
        if(outfile.is_open())
        {
            for(int i=0;i<studentcount;++i)
            {
                outfile << current->getstudentID() << " ";
                outfile << current->getname() << " ";
                for(int j=0;j<10;++j)
                    outfile << current->getsubject()[j] << " ";
                current = current->getnext();
                outfile << endl;
            }
        }
        else
        {
            cout << "���ļ�ʧ�ܣ�" << endl;
            return;
        }
    }
    /*********************************����д���ļ�*******************************/
    void outFileReverse(const string& str)
    {
        ofstream outfile(str);
        Student* current(tail);
        if(outfile.is_open())
        {
            for(int i=0;i<studentcount;++i)
            {
                outfile << current->getstudentID() << " ";
                outfile << current->getname() << " ";
                for(int j=0;j<10;++j)
                    outfile << current->getsubject()[j] << " ";
                current = current->getprev();
            }
        }
        else
        {
            cout << "���ļ�ʧ�ܣ�" << endl;
            return;
        }
    }
    /********************************����ʽ���뺯��********************************/
    void interaction()
    {
        system("cls");
        string stopflag("1");
        while(stopflag!="0")
      {
        cout << "������ѧ����ѧ��(ע��:ѧ��Ψһ�Ҳ��ɸ���):" << endl;
        cout << "��ʽΪ:��ѧ���/���/���ڱ��,��ѧ�������ΧΪ1990-2017,"
        "�������ΧΪ01-99,���ڱ������ΧΪ01-99" << endl;
        int aID(0);
        cin >> aID;
        while(aID>20179999 || aID<19900101)
        {
            cout << "ѧ�Ÿ�ʽ����,�����°��ո�ʽҪ������:" << endl;
            cout << "��ʽΪ:��ѧ���/���/���ڱ��,��ѧ�������ΧΪ1990-2017,"
            "�������ΧΪ01-99,���ڱ������ΧΪ01-99" << endl;
            cin >> aID;
        }
        cout << "��ʽ��ȷ,���������ظ�0,�����޸���ظ�����:" << endl;
        string aflag("0");
        cin >> aflag;
        while(aflag!="0")
        {
            cout << "������ѧ����ѧ��(ע��:ѧ��Ψһ�Ҳ��ɸ���):" << endl;
            cout << "��ʽΪ:��ѧ���/���/���ڱ��,��ѧ�������ΧΪ1990-2017,"
            "�������ΧΪ01-99,���ڱ������ΧΪ01-99" << endl;
            cin >> aID;
            while(aID>20179999 || aID<19900101)
            {
               cout << "ѧ�Ÿ�ʽ����,�����°��ո�ʽҪ������:" << endl;
               cout << "��ʽΪ:��ѧ���/���/���ڱ��,��ѧ�������ΧΪ1990-2017,"
               "�������ΧΪ01-99,���ڱ������ΧΪ01-99" << endl;
               cin >> aID;
            }
            cout << "��ʽ��ȷ,���������ظ�0,�����޸���ظ�����:" << endl;
            cin >> aflag;
        }
        /*****************************/
        cout << "������ѧ����������" << endl;
        string tempstr;
        cin >> tempstr;
        cout << "���뷵���޸���ظ�1,������ظ�0:" << endl;
        cin >> aflag;
        while(aflag!="0")
        {
             cout << "������ѧ����������" << endl;
             cin >> tempstr;
             cout << "���������ظ�0,�����޸���ظ�����:" << endl;
             cin >> aflag;
        }
        /********************************/
        int grade[10]={0};
        cout << "������ѧ��ʮ�ſγ̵ĳɼ�:(�޳ɼ�����0����,�ɼ���ɷ�ΧΪ0-100)" << endl;
        for(int i=0;i<10;++i)
        {
            cout << "��" << i+1 << "�ſγ̳ɼ�:  ";
            cin >> grade[i];
            while(grade[i]>100||grade[i]<0)
            {
                cout << "�ɼ��������󣡷�Χ�޶�0-100.����������: ";
                cin >> grade[i];
            }
        }
        /***********************************/
        //�����ʱ����Ϊ��
        if(head==nullptr)
        {
            head = new Student(aID,tempstr);
            head->setsubject(grade);
            head->settotalscore();
            head->setaveragescore();
            tail = head;
            studentcount++;
            for(int m=0;m<10;++m)  //��һ��������̨
            {
                minscore[m] = head->getsubject()[m];
                maxscore[m] = head->getsubject()[m];
                allscore[m] = 0;
            }
            for(int m=0;m<10;++m)
            {
                allscore[m] += head->getsubject()[m];
                if(head->getsubject()[m] < minscore[m])
                    minscore[m] = head->getsubject()[m];
                if(head->getsubject()[m] > maxscore[m])
                    maxscore[m] = head->getsubject()[m];
            }
            for(int m=0;m<10;++m)
            {
                averscore[m] = allscore[m] / studentcount;
            }
        }
        //�����ʱ����Ϊ��
        else
        {
            //����Ӧ�����λ��
            Student* tempp1(nullptr);
            if(aID < head->getstudentID())
            {
                tempp1 = new Student(aID,tempstr);
                tempp1->setsubject(grade);
                tempp1->settotalscore();
                tempp1->setaveragescore();
                tempp1->setnext(head);
                head->setprev(tempp1);
                head = tempp1;
                studentcount++;
                for(int m=0;m<10;++m)
                {
                    allscore[m] += tempp1->getsubject()[m];
                    if(tempp1->getsubject()[m] < minscore[m])
                        minscore[m] = tempp1->getsubject()[m];
                    if(tempp1->getsubject()[m] > maxscore[m])
                        maxscore[m] = tempp1->getsubject()[m];
                }
                for(int m=0;m<10;++m)
                {
                    averscore[m] = allscore[m] / studentcount;
                }
            }
            else if(aID > tail->getstudentID())
            {
                tempp1 = new Student(aID,tempstr);
                tempp1->setsubject(grade);
                tempp1->setprev(tail);
                tempp1->settotalscore();
                tempp1->setaveragescore();
                tail->setnext(tempp1);
                tail = tempp1;
                studentcount++;
                for(int m=0;m<10;++m)
                {
                    allscore[m] += tempp1->getsubject()[m];
                    if(tempp1->getsubject()[m] < minscore[m])
                        minscore[m] = tempp1->getsubject()[m];
                    if(tempp1->getsubject()[m] > maxscore[m])
                        maxscore[m] = tempp1->getsubject()[m];
                }
                for(int m=0;m<10;++m)
                {
                    averscore[m] = allscore[m] / studentcount;
                }
            }
            else
            {
                Student* tempp2(head);
                while(true)
                {
                    if(tempp2->getstudentID()<aID && tempp2->getnext()->getstudentID()>aID)
                    {
                        //��Ӧ����tempp2��tempp2��next֮��
                        tempp1 = new Student(aID,tempstr);
                        tempp1->setsubject(grade);
                        tempp1->settotalscore();
                        tempp1->setaveragescore();
                        tempp1->setprev(tempp2);
                        tempp1->setnext(tempp2->getnext());
                        tempp2->setnext(tempp1);
                        tempp1->getnext()->setprev(tempp1);
                        studentcount++;
                        for(int m=0;m<10;++m)
                        {
                            allscore[m] += tempp1->getsubject()[m];
                            if(tempp1->getsubject()[m] < minscore[m])
                                minscore[m] = tempp1->getsubject()[m];
                            if(tempp1->getsubject()[m] > maxscore[m])
                                maxscore[m] = tempp1->getsubject()[m];
                        }
                        for(int m=0;m<10;++m)
                        {
                            averscore[m] = allscore[m] / studentcount;
                        }
                        break;
                    }
                    tempp2 = tempp2->getnext();

                }
            }
        }
        cout << "�����ټ���¼������ѧ����Ϣ��ظ�0,������ظ�����:  ";
        cin >> stopflag;
      }
    }
    /********************************��ȡ�ļ�********************************/
    void readfile()
    {
        ifstream infile("studentmessage.txt");
        if(infile.is_open())
        {
            if(infile.eof())
            {
                cout << "�����ļ�Ϊ�գ�" << endl;
                return;
            }
            else
            {
                int tempID(0);
                string tempstr;
                int tempsub[10]={0};
              while(!infile.eof())
              {
                infile >> tempID >> tempstr;
                for(int j=0;j<10;++j)
                    infile >> tempsub[j];
                //�����ʱ����Ϊ��
                if(head==nullptr)
                {
                    head = new Student(tempID,tempstr);
                    head->setsubject(tempsub);
                    head->settotalscore();
                    head->setaveragescore();
                    tail = head;
                    studentcount++;
                    for(int m=0;m<10;++m)  //��һ��������̨
                    {
                        minscore[m] = head->getsubject()[m];
                        maxscore[m] = head->getsubject()[m];
                        allscore[m] = 0;
                    }
                    for(int m=0;m<10;++m)
                    {
                        allscore[m] += head->getsubject()[m];
                        if(head->getsubject()[m] < minscore[m])
                            minscore[m] = head->getsubject()[m];
                        if(head->getsubject()[m] > maxscore[m])
                            maxscore[m] = head->getsubject()[m];
                    }
                    for(int m=0;m<10;++m)
                    {
                        averscore[m] = allscore[m] / studentcount;
                    }
                }
                //�����ʱ����Ϊ��
                else if(head!=nullptr)
                {
                    //cout << "1" << endl;
                    //����Ӧ�����λ��
                    Student* tempp1(nullptr);
                    if(tempID < head->getstudentID())
                    {
                        //cout << "2" << endl;
                        tempp1 = new Student(tempID,tempstr);
                        tempp1->setsubject(tempsub);
                        tempp1->settotalscore();
                        tempp1->setaveragescore();
                        tempp1->setnext(head);
                        head->setprev(tempp1);
                        head = tempp1;
                        studentcount++;
                        for(int m=0;m<10;++m)
                        {
                            allscore[m] += tempp1->getsubject()[m];
                            if(tempp1->getsubject()[m] < minscore[m])
                                minscore[m] = tempp1->getsubject()[m];
                            if(tempp1->getsubject()[m] > maxscore[m])
                                maxscore[m] = tempp1->getsubject()[m];
                        }
                        for(int m=0;m<10;++m)
                        {
                            averscore[m] = allscore[m] / studentcount;
                        }
                     }
                    if(tempID > tail->getstudentID())
                    {
                        //cout << "3" << endl;
                        tempp1 = new Student(tempID,tempstr);
                        tempp1->setsubject(tempsub);
                        tempp1->setprev(tail);
                        tempp1->settotalscore();
                        tempp1->setaveragescore();
                        tail->setnext(tempp1);
                        tail = tempp1;
                        studentcount++;
                        for(int m=0;m<10;++m)
                        {
                            allscore[m] += tempp1->getsubject()[m];
                            if(tempp1->getsubject()[m] < minscore[m])
                                minscore[m] = tempp1->getsubject()[m];
                            if(tempp1->getsubject()[m] > maxscore[m])
                                maxscore[m] = tempp1->getsubject()[m];
                        }
                        for(int m=0;m<10;++m)
                        {
                            averscore[m] = allscore[m] / studentcount;
                        }
                    }
                    if(tempID < tail->getstudentID() && tempID > head->getstudentID())
                    {
                        //cout << "4" << endl;
                        Student* tempp2(head);
                        while(true)
                        {
                             //cout <<"5" << endl;
                             if(tempp2->getstudentID() < tempID && tempp2->getnext()->getstudentID() > tempID)
                             {
                                 //��tempp1Ӧ����tempp2��tempp2��next֮��
                                 tempp1 = new Student(tempID,tempstr);
                                 tempp1->setsubject(tempsub);
                                 tempp1->settotalscore();
                                 tempp1->setaveragescore();
                                 tempp1->setprev(tempp2);
                                 tempp1->setnext(tempp2->getnext());
                                 tempp2->setnext(tempp1);
                                 tempp1->getnext()->setprev(tempp1);
                                 studentcount++;
                                 for(int m=0;m<10;++m)
                                 {
                                    allscore[m] += tempp1->getsubject()[m];
                                    if(tempp1->getsubject()[m] < minscore[m])
                                        minscore[m] = tempp1->getsubject()[m];
                                    if(tempp1->getsubject()[m] > maxscore[m])
                                        maxscore[m] = tempp1->getsubject()[m];
                                 }
                                 for(int m=0;m<10;++m)
                                 {
                                     averscore[m] = allscore[m] / studentcount;
                                 }
                                 break;
                             }
                             tempp2 = tempp2->getnext();

                        }
                    }

            }
        }
        }
        }
        else
        {
            cout <<"�򿪱����ļ�ʧ�ܣ�" << endl;
        }
        infile.close();
    }
    /*******************************���ض�ȡ�ļ���������ȡָ��·��********************************/
    void readfile(const string& str)
    {
        f=str;
        flag=true;
        ifstream infile(str);
        if(infile.is_open())
        {
            if(infile.eof())
            {
                cout << "�����ļ�Ϊ�գ�" << endl;
                return;
            }
            else
            {
                int tempID(0);
                string tempstr;
                int tempsub[10]={0};
              while(!infile.eof())
              {
                infile >> tempID >> tempstr;
                for(int j=0;j<10;++j)
                    infile >> tempsub[j];
                //�����ʱ����Ϊ��
                if(head==nullptr)
                {
                    head = new Student(tempID,tempstr);
                    head->setsubject(tempsub);
                    head->settotalscore();
                    head->setaveragescore();
                    tail = head;
                    studentcount++;
                    for(int m=0;m<10;++m)  //��һ��������̨
                    {
                        minscore[m] = head->getsubject()[m];
                        maxscore[m] = head->getsubject()[m];
                        allscore[m] = 0;
                    }
                    for(int m=0;m<10;++m)
                    {
                        allscore[m] += head->getsubject()[m];
                        if(head->getsubject()[m] < minscore[m])
                            minscore[m] = head->getsubject()[m];
                        if(head->getsubject()[m] > maxscore[m])
                            maxscore[m] = head->getsubject()[m];
                    }
                    for(int m=0;m<10;++m)
                    {
                        averscore[m] = allscore[m] / studentcount;
                    }
                }
                //�����ʱ����Ϊ��
                else if(head!=nullptr)
                {
                    //cout << "1" << endl;
                    //����Ӧ�����λ��
                    Student* tempp1(nullptr);
                    if(tempID < head->getstudentID())
                    {
                        //cout << "2" << endl;
                        tempp1 = new Student(tempID,tempstr);
                        tempp1->setsubject(tempsub);
                        tempp1->settotalscore();
                        tempp1->setaveragescore();
                        tempp1->setnext(head);
                        head->setprev(tempp1);
                        head = tempp1;
                        studentcount++;
                        for(int m=0;m<10;++m)
                        {
                            allscore[m] += tempp1->getsubject()[m];
                            if(tempp1->getsubject()[m] < minscore[m])
                                minscore[m] = tempp1->getsubject()[m];
                            if(tempp1->getsubject()[m] > maxscore[m])
                                maxscore[m] = tempp1->getsubject()[m];
                        }
                        for(int m=0;m<10;++m)
                        {
                            averscore[m] = allscore[m] / studentcount;
                        }
                     }
                    if(tempID > tail->getstudentID())
                    {
                        //cout << "3" << endl;
                        tempp1 = new Student(tempID,tempstr);
                        tempp1->setsubject(tempsub);
                        tempp1->setprev(tail);
                        tempp1->settotalscore();
                        tempp1->setaveragescore();
                        tail->setnext(tempp1);
                        tail = tempp1;
                        studentcount++;
                        for(int m=0;m<10;++m)
                        {
                            allscore[m] += tempp1->getsubject()[m];
                            if(tempp1->getsubject()[m] < minscore[m])
                                minscore[m] = tempp1->getsubject()[m];
                            if(tempp1->getsubject()[m] > maxscore[m])
                                maxscore[m] = tempp1->getsubject()[m];
                        }
                        for(int m=0;m<10;++m)
                        {
                            averscore[m] = allscore[m] / studentcount;
                        }
                    }
                    if(tempID < tail->getstudentID() && tempID > head->getstudentID())
                    {
                        //cout << "4" << endl;
                        Student* tempp2(head);
                        while(true)
                        {
                             //cout <<"5" << endl;
                             if(tempp2->getstudentID() < tempID && tempp2->getnext()->getstudentID() > tempID)
                             {
                                 //��tempp1Ӧ����tempp2��tempp2��next֮��
                                 tempp1 = new Student(tempID,tempstr);
                                 tempp1->setsubject(tempsub);
                                 tempp1->settotalscore();
                                 tempp1->setaveragescore();
                                 tempp1->setprev(tempp2);
                                 tempp1->setnext(tempp2->getnext());
                                 tempp2->setnext(tempp1);
                                 tempp1->getnext()->setprev(tempp1);
                                 studentcount++;
                                 for(int m=0;m<10;++m)
                                 {
                                    allscore[m] += tempp1->getsubject()[m];
                                    if(tempp1->getsubject()[m] < minscore[m])
                                        minscore[m] = tempp1->getsubject()[m];
                                    if(tempp1->getsubject()[m] > maxscore[m])
                                        maxscore[m] = tempp1->getsubject()[m];
                                 }
                                 for(int m=0;m<10;++m)
                                 {
                                     averscore[m] = allscore[m] / studentcount;
                                 }
                                 break;
                             }
                             tempp2 = tempp2->getnext();

                        }
                    }

            }
        }
        }
        }
        else
        {
            cout <<"�򿪱����ļ�ʧ�ܣ�" << endl;
        }
        infile.close();
    }
    /*******************************�����ӡ********************************/
    void displayInorder()
    {
        system("cls");
        if(studentcount==0)
        {
            cout << "��Ϊ�գ�" << endl;
            return;
        }
        cout << "��ǰ����ѧ����" << studentcount << "��" << endl;
        cout << "   ѧ��     ����      ��Ŀ1  ��Ŀ2  ��Ŀ3  ��Ŀ4  ��Ŀ5  ��Ŀ6  ��Ŀ7  ��Ŀ8  ��Ŀ9  ��Ŀ10  �ܳɼ�  ƽ���ɼ�" <<endl;
        Student* tempp(head);
        for(int i=0;i<studentcount;++i)
        {
            cout << tempp->getstudentID() << "    " << tempp->getname() << "       ";
            for(int j=0;j<10;++j)
                cout << tempp->getsubject()[j] << "     ";
            cout << tempp->gettotalscore() << "     " << tempp->getaveragescore() ;
            cout << endl;
            tempp = tempp->getnext();
        }
        system("pause");
    }
    /*******************************�����ӡ********************************/
    void displayReverse()
    {
        system("cls");
        if(studentcount==0)
        {
            cout << "��Ϊ�գ�" << endl;
            return;
        }
        cout << "��ǰ����ѧ����" << studentcount << "��" << endl;
        cout << "   ѧ��     ����      ��Ŀ1  ��Ŀ2  ��Ŀ3  ��Ŀ4  ��Ŀ5  ��Ŀ6  ��Ŀ7  ��Ŀ8  ��Ŀ9  ��Ŀ10  �ܳɼ�  ƽ���ɼ�" <<endl;
        Student* tempp(tail);
        for(int i=0;i<studentcount;++i)
        {
            cout << tempp->getstudentID() << "    " << tempp->getname() << "       ";
            for(int j=0;j<10;++j)
                cout << tempp->getsubject()[j] << "     ";
            cout << tempp->gettotalscore() << "     " << tempp->getaveragescore() ;
            cout << endl;
            tempp = tempp->getprev();
        }
        system("pause");
    }
    /*******************************��ӡ��Ϻ���*********************************/
    void display()
    {
        system("cls");
        cout<<"��ѡ�����ѧ����Ϣ��˳��1.����2.���򣩣�";
        int n=0;
        cin>>n;
        while(n!=1&&n!=2)
        {
            cout<<"�����������������룡"<<endl;
            cin>>n;
        }
        if(n==1)
        {
            this->displayInorder();
            if(flag==false)
                this->outFileInOrder("studentmessage.txt");
            if(flag==true)
                this->outFileInOrder(f);
        }
        if(n==2)
        {
            this->displayReverse();
            if(flag==false)
                this->outFileReverse("studentmessage.txt");
            if(flag==true)
                this->outFileReverse(f);
        }
    }
    /*********************************��ȡ�ļ���Ϻ���*******************************/
    void read_file()
    {
        system("cls");
        string str;
        cout<<"�������ļ�����·����";
        cin>>str;
        this->clearList();
        this->readfile(str);
        system("pause");
    }
    /********************************��Ŀ����ͳ����Ϻ���********************************/
    void substatistics()
    {
        system("cls");
        cout<<"������ͳ�ƿ�Ŀ�����ݣ�1.��߷֣�2.��ͷ֣�3.ƽ���֣�:";
        int n=0;
        cin>>n;
        while(n!=1&&n!=2&&n!=3)
        {
            cout<<"�����������������룺";
            cin>>n;
        }
        if(n==1)
        {
            cout<<"������Ҫ��ѯ�Ŀ�Ŀ���루1-10����ȫ����Ŀ��0����";
            int i=-1;
            cin>>i;
            while(i<0||i>10)
            {
                cout<<"�����������������룺";
                cin>>i;
            }
            if(i==0)
            {
                this->displaymaxscore();
            }
            else
            {
                this->displaymaxscore(i-1);
            }
        }
        if(n==2)
        {
            cout<<"������Ҫ��ѯ�Ŀ�Ŀ���루1-10����ȫ����Ŀ��0����";
            int i=-1;
            cin>>i;
            while(i<0||i>10)
            {
                cout<<"�����������������룺";
                cin>>i;
            }
            if(i==0)
            {
                this->displayminscore();
            }
            else
            {
                this->displayminscore(i-1);
            }
        }
        if(n==3)
        {
            cout<<"������Ҫ��ѯ�Ŀ�Ŀ���루1-10����ȫ����Ŀ��0����";
            int i=-1;
            cin>>i;
            while(i<0||i>10)
            {
                cout<<"�����������������룺";
                cin>>i;
            }
            if(i==0)
            {
                this->displayaverscore();
            }
            else
            {
                this->displayaverscore(i-1);
            }
        }
    }
    /********************************��ѯѧ����Ϣ��Ϻ���*********************************/
    void searchstudent()
    {
        system("cls");
        StudentStruct astruct(this->getstudentcount());
        astruct.readtostruct(this->gethead());
        cout<<"������Ҫ��ѯ����Ϣ��1.ѧ�ţ�2.��������";
        int n=0;
        cin>>n;
        while(n!=1&&n!=2)
        {
            cout<<"�����������������룺";
            cin>>n;
        }
        if(n==1)
        {
            ID_ExactSearch(astruct);
        }
        if(n==2)
        {
            cout<<"�������ѯ��ʽ��1.��ȷ��ѯ��2.ģ����ѯ����";
            int m=0;
            cin>>m;
            while(m!=1&&m!=2)
            {
                cout<<"�����������������룺";
                cin>>m;
            }
            if(m==1)
            {
                Name_ExactSearch(astruct);
            }
            if(m==2)
            {
                Name_FuzzySearch(astruct);
            }
        }
    }
    /*********************************�ɼ�������Ϻ���*********************************/
    void gradesort()
    {
        system("cls");
        StudentStruct astruct(this->getstudentcount());
        astruct.readtostruct(this->gethead());
        cout<<"��������������ɼ��Ŀ�Ŀ����Ŀ1-10���ܳɼ�11����";
        int i;
        cin>>i;
        while(i<1||i>11)
        {
            cout<<"����������������룺";
            cin>>i;
        }
        switch(i)
        {
        case 1:Sort(1,astruct);break;
        case 2:Sort(2,astruct);break;
        case 3:Sort(3,astruct);break;
        case 4:Sort(4,astruct);break;
        case 5:Sort(5,astruct);break;
        case 6:Sort(6,astruct);break;
        case 7:Sort(7,astruct);break;
        case 8:Sort(8,astruct);break;
        case 9:Sort(9,astruct);break;
        case 10:Sort(10,astruct);break;
        case 11:Sort(11,astruct);break;
        }
    }
};
#endif // STUDENTLIST_H

