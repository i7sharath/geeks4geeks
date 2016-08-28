#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int add1(int x)
{
	int m=1;
	while(x & m)
	{
		x=x ^ m;
		m=m<<1;
	}

	x=x ^ m;
	return x;
}

int main()
{
	int x;
	cin>>x;
	cout<<add1(x)<<endl;
	return 0;
}