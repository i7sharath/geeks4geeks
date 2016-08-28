#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

void reverseBits(unsigned int n)
{
	unsigned int index=(sizeof(n)*8)-1;
	unsigned reversenum=0;
	while(n>0)
	{
		if(n&1)
			reversenum+=pow(2,index);
		n=n>>1;
		index--;
	}
	cout<<reversenum<<endl;
	return;
}


int main()
{
	int n;
	cin>>n;
	reverseBits(n);
	return 0;
}