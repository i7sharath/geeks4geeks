#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>

using namespace std;

bool isbitset(unsigned int n,int k)
{
	return n & (1<<k-1)?true:false;
}


bool palindrome(unsigned int n)
{
	int l=0;
	int r=sizeof(unsigned int)*8;
	while(l<r)
	{
		if(isbitset(n,l)!=isbitset(n,r))
			return false;
		else
		{
			l++;
			r--;
		}
	}
	return true;
}

int main()
{
	unsigned int n=1<<15 + 1<<16;
	cout<<palindrome(n)<<endl;
	return 0;
}