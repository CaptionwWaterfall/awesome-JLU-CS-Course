#include <stdio.h>
#include <math.h>
int main()
{
    int x;
	scanf("%d",&x);
	if(x%3==0)
		printf("�ܱ�3����\n");
    if(x%5==0)
		printf("�ܱ�5����\n");
	if(x%7==0)
		printf("�ܱ�7����\n");
    if((x%7==0)&&(x%5==0)&&(x%3==0))
		printf("��ͬʱ������������\n");
	if((x%7==0)&&(x%5==0))
		printf("��ͬʱ��7��5����\n");
	if((x%5==0)&&(x%3==0))
		printf("��ͬʱ��5��3����\n");
	if((x%7==0)&&(x%3==0))
		printf("��ͬʱ��7��3����\n");
	return 0;
    
}


