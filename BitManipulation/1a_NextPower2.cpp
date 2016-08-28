//Next power of two

#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

void NextPower2(unsigned n)
{
	int pos=ceil(log(n)/log(2));
	int ans=pow(2,pos);
	cout<<ans<<endl;
	return;
}

int main()
{
	unsigned n;
	cin>>n;
	NextPower2(n);
	return 0;
}