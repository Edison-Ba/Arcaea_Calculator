// Arcaea ???????????   Made by??EdisonBa 
#include<cstdio>
#include<cmath>
#include<iostream>
#include<windows.h>
using namespace std;
int main()
{
	double dan,a,b,c,sum,score;
	double p;
	cout<<"Arcaea??????score????"<<endl;
	cout<<endl;
	cout<<"  ??PURE??????";
	cin>>a;
	cout<<endl;
	cout<<"  ??pure????" <<endl;
	cout<<"????��???????0??" <<endl;
	cout<<"  ?????p??????" ;
	cin>>p;
	cout<<endl<<"  FAR??????";
	cin>>b;
	cout<<endl<<"  LOST??????";
	cin>>c;
	cout<<endl;
	sum=a+b+c;
	dan=(10000000+sum)/sum;
	if(p==0)
		p=a;
	//printf("%.0lf %.8lf",sum,dan);
	score=a*dan+0.5*b*dan-(a-p)-b;
	printf("  ????score??%.0lf\n" ,score);
	cout<<endl<<"Made by: EdisonBa."<<endl;
	system("Pause");
	return 0;
	
	
}
