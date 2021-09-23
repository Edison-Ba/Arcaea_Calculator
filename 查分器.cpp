#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
const int PM=10000000,EX=9800000;
int main()
{
//	freopen("arc23.in","r",stdin);
//	freopen("arc23.out","w",stdout);
	double dan,a,b,c,d,sum,ptt,score;
	double p;
	string str;
	getline(cin,str);
	cin>>a;//总PURE 
	cin>>p;//大p 
	cin>>b;//FAR
	cin>>c;//LOST
	cin>>d;//定数 
	sum=a+b+c;//物量
	 
	dan=(double)10000000/sum;//每个note的价值 

	//printf("%.0lf %.8lf",sum,dan);
	score=a*dan+0.5*b*dan+p;
	printf("%08d\n",(int)score);
	if(score>=PM)
		printf ("%.2lf",2+d);
	else
	{
		if(score>=EX) 
			ptt=2+d+((score-PM)/200000);
		else 
			ptt=1+d+((score-EX)/300000);
		if(ptt>0)
			printf ("%.2lf",ptt);
		else cout<<"0.00";
	}
	return 0;
}