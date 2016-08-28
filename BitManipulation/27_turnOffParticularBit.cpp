#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

unsigned int turnOffParticularBit(unsigned int n,unsigned int k)
{
	if(k<=0)
		return 0;
	unsigned int m=1;
		m<<=(k-1);
	return (n & ~m);
}

int main()
{
	unsigned int n,k;
	cin>>n>>k;
	cout<<turnOffParticularBit(n,k)<<endl;
	return 0;
} 