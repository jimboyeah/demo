// 计算 y 年是农历什么年

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
	int t,d;		// 分别表示天干、地支
	char tian_g[]="甲乙丙丁戊己庚辛壬癸";
	char di_z[]="子丑寅卯辰巳午未申酉戌亥";
	t=((y-4)%10+10)%10;
	d=((y-4)%12+12)%12;
	cout<<"\n\n\t公元 "<<y<<" 年是农历 "<<tian_g[t*2]<<tian_g[t*2+1]<<di_z[d*2]<<di_z[d*2+1]<<" 年"<<endl<<endl;
}


