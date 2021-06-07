// Arcaea查单曲ptt工具  Made by: EdisonBa.

#include<iostream>
#include<cstdio>
#include<math.h>
#include<cmath>
using namespace std;
const int PM=10000000,EX=9800000;
int main()
{
	double n,d,ptt; 
	cout<<"Arcaea查单曲ptt工具"<<endl;
	cout<<endl;
	cout<<"定数：";
	cin>>d;
	cout<<endl; 
	cout<<"Score：";
	cin>>n;
	cout<<endl; 
	if(n>=PM)
		printf ("%s %.2lf","Ptt:",2+d);
	else
	{
		if(n>=EX) 
			ptt=2+d+((n-PM)/200000);
		else 
			ptt=1+d+((n-EX)/300000);
		if(ptt>0)
			printf ("%s %.2lf","Ptt:",ptt);
		else cout<<"Ptt: 0";
	}
	cout<<" "<<endl;
	cout<<" "<<endl;
	cout<<"Made by: EdisonBa."<<endl;
	getchar();
	
	return 0;
}

