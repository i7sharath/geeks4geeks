#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int countSwapBits(unsigned int n1,unsigned int n2)
{
	int swapbits=0;
	unsigned int n3=n1 ^ n2;
	while(n3>0)
	{
		if(n3 & 1)
			swapbits++;
		n3=n3>>1;
	}
	return swapbits;
}

int main()
{
	unsigned int n1,n2;
	cin>>n1>>n2;
	int swapbits=countSwapBits(n1,n2);
	cout<<swapbits<<endl;
	return 0;
}

