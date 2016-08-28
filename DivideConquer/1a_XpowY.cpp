#include <bits/stdc++.h>

using namespace std;

double xPowy(double x,int y)
{
	if(x==0)
		return 0;
	if(y==0)
		return 1;
	if(y==1)
		return x;
	if(y%2==0)
	{
		double c=xPowy(x,y/2);
		return c*c;
	}
	else
	{
		double c=xPowy(x,y/2);
		return x*c*c;
	}
}


int main()
{
	int x,y;
	cin>>x>>y;
	cout<<xPowy(x,y)<<endl;
	return 0;
}