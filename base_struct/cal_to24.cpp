
// 产生4个1-10的随机数，并将它们计算得到24

#include<iostream.h>
#include<stdlib.h>
#include<ctime>
#include<math.h>
int t[4],s[3];
float m[4];
bool cal24a();
bool cal24b();
float cal2(float,float,int);
void main()
{	
	int i;	
	char exit='n';
	while(exit!='0')
	{
		srand((unsigned)time(0));
		cout<<"\n\n\t4 numbers are : ";
		for(i=0;i<4;i++)
		{
			t[i]=rand()%10+1;		// 产生4个随机数
			cout<<"\t"<<t[i];
		}
		cout<<endl<<endl<<"\t";
		if(!cal24a())
			cout<<"No Solution !";

		cout<<"\n\n\tPress 0 to EXIT or other key to Continue : ";
		cin>>exit;
	}	
	cout<<endl;
}

bool cal24a()
{
	int i,j,k,x,y,z;
	for(x=0;x<4;x++)
		for(y=0;y<4;y++)
			if(y!=x)				
				for(z=0;z<4;z++)				
					if(z!=y&&z!=x)
					{
						m[0]=(float)t[x],m[1]=(float)t[y],m[2]=(float)t[z],m[3]=(float)t[6-x-y-z];
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								for(k=0;k<4;k++)
								{
									s[0]=i,s[1]=j,s[2]=k;
									if(cal24b()) return true;
								}
						
					}			
	return false;
}

bool cal24b()
{
	char sign[]="+-*/";
	if(fabs(cal2(cal2(cal2(m[0],m[1],s[0]),m[2],s[1]),m[3],s[2])-24)<0.0001)
	{
		cout<<"( ( "<<m[0]<<" "<<sign[s[0]]<<" "<<m[1]<<" ) "<<sign[s[1]]<<" "<<m[2]<<" ) "<<sign[s[2]]<<" "<<m[3]<<" = 24";
		return true;
	}
	if(fabs(cal2(cal2(m[0],m[1],s[0]),cal2(m[2],m[3],s[2]),s[1])-24)<0.0001)
	{
		cout<<"( "<<m[0]<<" "<<sign[s[0]]<<" "<<m[1]<<" ) "<<sign[s[1]]<<" ( "<<m[2]<<" "<<sign[s[2]]<<" "<<m[3]<<" ) = 24";
		return true;
	}
	if(fabs(cal2(cal2(m[0],cal2(m[1],m[2],s[1]),s[0]),m[3],s[2])-24)<0.0001)
	{
		cout<<"( "<<m[0]<<" "<<sign[s[0]]<<" ( "<<m[1]<<" "<<sign[s[1]]<<" "<<m[2]<<" ) ) "<<sign[s[2]]<<" "<<m[3]<<" = 24";
		return true;
	}
	if(fabs(cal2(m[0],cal2(cal2(m[1],m[2],s[1]),m[3],s[2]),s[0])-24)<0.0001)
	{
		cout<<m[0]<<" "<<sign[s[0]]<<" ( ( "<<m[1]<<" "<<sign[s[1]]<<" "<<m[2]<<" ) "<<sign[s[2]]<<" "<<m[3]<<" ) = 24";
		return true;
	}
	if(fabs(cal2(m[0],cal2(m[1],cal2(m[2],m[3],s[2]),s[1]),s[0])-24)<0.0001)
	{
		cout<<m[0]<<" "<<sign[s[0]]<<" ( "<<m[1]<<" "<<sign[s[1]]<<" ( "<<m[2]<<" "<<sign[s[2]]<<" "<<m[3]<<" ) ) = 24";
		return true;
	}

	return false;
}

float cal2(float x,float y,int z)
{
	switch(z)
	{
	case 0:return x+y;
	case 1:return x-y;
	case 2:return x*y;
	case 3:return x/y;
	}
	return -1000;
}
