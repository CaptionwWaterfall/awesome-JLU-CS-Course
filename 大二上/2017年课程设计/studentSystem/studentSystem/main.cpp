#include "StudentList.h"

void menu();
int main(){
    StudentList alist;//ʵ����
    int n;
    menu();
    cin>>n;
    alist.readfile();
	while(n){
		switch(n){
		case 1:alist.read_file();break;
		case 2:alist.interaction();break;
		case 3:alist.insertstudent();break;
		case 4:alist.changemessage();break;
		case 5:alist.deletestudent();break;
		case 6:alist.searchstudent();break;
		case 7:alist.gradesort();break;
		case 8:alist.substatistics();break;
		case 9:alist.display();break;
		case 0:break;
		}
		menu();
		cin>>n;
	}    //���˵�
}

void menu()
{
	system("cls");
	cout<<"\n\n\n\n\n";
	cout<<"\t\t|---------------------ѧ����Ϣ����ϵͳ-------------------|\n";
	cout<<"\t\t|\t 1. ���ļ�������Ϣ                               |\n";
	cout<<"\t\t|\t 2. ����ʽ¼��ѧ����Ϣ                           |\n";
	cout<<"\t\t|\t 3. ����ѧ����Ϣ                                 |\n";
	cout<<"\t\t|\t 4. �޸�ѧ����Ϣ                                 |\n";
	cout<<"\t\t|\t 5. ɾ��ѧ����Ϣ                                 |\n";
	cout<<"\t\t|\t 6. ��ѯѧ����Ϣ                                 |\n";
	cout<<"\t\t|\t 7. �ɼ�����                                     |\n";
	cout<<"\t\t|\t 8. ��Ŀ����ͳ��                                 |\n";
	cout<<"\t\t|\t 9. ���ѧ����Ϣ                                 |\n";
	cout<<"\t\t|\t 0. �˳�                                         |\n";
	cout<<"\t\t|--------------------------------------------------------|\n\n";
	cout<<"\t\t\t������(0-9):";
}
