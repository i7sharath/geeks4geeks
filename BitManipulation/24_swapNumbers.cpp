#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void swap(int x,int y)
{
	x=x+y;
	y=x-y;
	x=x-y;
	cout<<"x="<<x<<" "<<"y="<<y<<endl;
	return ;
}

int main()
{
	int x,y;
	cin>>x>>y;
	swap(x,y);
	return 0;
}