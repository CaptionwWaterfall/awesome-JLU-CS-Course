#include<stdio.h>
main(){
	int a[7],i,j,n,m;
	n=7;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);  //��������
	}
    for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{         //�ж��Ƿ�����ͬԪ��
				for(m=j;m<n-1;m++)
				{
				  a[m]=a[m+1];       //��ǰ��1
				}
				n=n-1;              //������Ԫ�ؼ�1
				j=j-1;
			}
		}
	}
    for(i=0;i<n;i++){
	   printf("%d ",a[i]);   //���
	}

}
