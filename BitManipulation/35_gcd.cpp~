#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
	if(b==0 || a==b)
		return a;
	if(a==0)
		return b;
	if((a&1==0) && (b&1==0))
		return gcd(a>>1,b>>1)<<1;
	else if((a&1==0) && (b&1!=0))
		return gcd(a>>1,b);
	else if((a&1!=0)&& (b&1==0))
		return gcd(a,b>>1);
	else
		return a>b?gcd(a-b,b):gcd(a,b-a);
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<endl;
	return 0;
}
