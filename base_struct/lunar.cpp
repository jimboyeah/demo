// ���� y ����ũ��ʲô��

#include<iostream.h>
void lunar_year(int);
void main()
{	
	int y;	
	
	cout<<"\nInput the year  : ";
	cin>>y;
	
	lunar_year(y);	

	cout<<endl<<endl;
}

void lunar_year(int y)
{
	int t,d;		// �ֱ��ʾ��ɡ���֧
	char tian_g[]="���ұ����켺�����ɹ�";
	char di_z[]="�ӳ���î������δ�����纥";
	t=((y-4)%10+10)%10;
	d=((y-4)%12+12)%12;
	cout<<"\n\n\t��Ԫ "<<y<<" ����ũ�� "<<tian_g[t*2]<<tian_g[t*2+1]<<di_z[d*2]<<di_z[d*2+1]<<" ��"<<endl<<endl;
}


