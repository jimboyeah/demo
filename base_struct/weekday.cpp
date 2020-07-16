
// 计算 y 年 m 月 d 日是星期几

#include<iostream.h>
#include<math.h>
void weekday(int,int,int);
void main()
{	
	int y,m,d;	
	
	cout<<"\nInput the year  : ";
	cin>>y;
	cout<<"\nInput the month : ";
	cin>>m;
	cout<<"\nInput the day   : ";
	cin>>d;
	
	weekday(y,m,d);	

	cout<<endl<<endl;
}

void weekday(int y,int m,int d)
{
	if(m<0||m>12||d<0||d>31||(m==4||m==6||m==9||m==11)&&d==31||m==2&&d>29||m==2&&d==29&&!(y%4==0&&y%100!=0||y%400==0)) 
	{
		cout<<"\n\n\tInput Data Error !";
	}
	else
	{
		int yr,dd,i,wkday;			
		yr=(int)((ceil)(y/4.)-(ceil)(y/100.)+(ceil)(y/400.));			// -1.12.31.~y.1.1.闰年数
		dd=y*365+yr;
		for(i=1;i<m;i++)
		{
			switch(i)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:dd+=31;break;	// 大月
			case 4:
			case 6:
			case 9:
			case 11:dd+=30;break;	// 小月
			default:
				if(y%4==0&&y%100!=0||y%400==0) dd+=29;
				else dd+=28;
			}
		}
		dd+=d+5;		// -1年12月31日是星期五
		wkday=(dd%7+7)%7;
		cout<<"\n\n\t公元 "<<y<<" 年 "<<m<<" 月 "<<d<<" 日是星期";
		switch(wkday)
		{
		case 0:cout<<"日\n\n";break;
		case 1:cout<<"一\n\n";break;
		case 2:cout<<"二\n\n";break;
		case 3:cout<<"三\n\n";break;
		case 4:cout<<"四\n\n";break;
		case 5:cout<<"五\n\n";break;
		default:cout<<"六\n\n";
		}
	}	
}


