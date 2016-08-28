#include <bits/stdc++.h>

using namespace std;

int subtract(int x,int y)
{
	int diff,borrow;
	while(y!=0)
	{
		borrow=(~x) & y;
		x=x^y;
		y=borrow<<1;
	}
	return x;
}

int main()
{
	int x,y;
	cin>>x>>y;
	cout<<subtract(x,y)<<endl;
	return 0;
}
