#include <stdio.h>
#include <math.h>
int main()
{
	float rx(float x);
	float m,n;
	float t;
	printf("please input m&n\n"); 
	scanf("%f%f",&m,&n);
	if(m<n)
	{
		t=m;
		m=n;
		n=t;
	}                           //���ǵ�n>m�����
    printf("%f\n",rx(m)/(rx(m-n)*rx(n)));
	return 0;

}
float rx(float x)               //�����׳�̫�鷳����ͬ�Ķ�β����ɶ��庯��
{
	float i;
	float p;
	p=1;
	for(i=x;i>=1;i--) p=p*i;    //ע��i>=1������i<=1(ѭ���ķ���Ҫ��ȷ)
    return(p);
}