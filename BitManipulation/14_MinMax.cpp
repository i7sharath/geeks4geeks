#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

int Min(int x,int y)
{
	return y ^ ((x ^ y) & -(x<y));
}
int Max(int x,int y)
{
	return x ^ ((x ^ y) & -(x<y));
}

int main()
{
	int n,m;
	cin>>m>>n;
	int num=Min(m,n);
	cout<<num<<endl;
	num=Max(m,n);
	cout<<num<<endl;
	return 0;
}