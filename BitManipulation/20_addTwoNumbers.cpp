#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int addTwoNumbers(int x,int y)
{
	while(y!=0)
	{
		int carry=x & y;
		x=x ^ y;
		y=carry<<1;
	}
	return x;
}


int main()
{
	int x,y;
	cin>>x>>y;
	cout<<addTwoNumbers(x,y)<<endl;
	return 0;
}