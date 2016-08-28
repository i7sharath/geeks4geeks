#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int checkPowerOf4(int n)
{
	if(n>0 && !(n &(n-1)))
	{
		int count=0;
		while(n>1)
		{
			count++;
			n=n>>1;
		}
		return (count%2==0? 1:0);
	}
}


int main()
{
	int n;
	cin>>n;
	int flag=checkPowerOf4(n);
	if(flag)
		cout<<"power of 4"<<endl;
	else
		cout<<"Not a power of 4"<<endl;
	return 0;
}