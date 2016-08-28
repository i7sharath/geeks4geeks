// Check whether a Number is amultiple of 3 

#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

void checkMultipleOf3(unsigned n)
{
	int oddcount=0,evencount=0;
	if(n==0)
	{
		cout<<"Multiple of 3"<<endl;
		return;
	}
	if(n==1)
	{
		cout<<"Not a Multiple of 3"<<endl;
		return;
	}
	while(n>0)
	{
		if(n & 1)
			oddcount++;
		n=n>>1;
		if(n & 1)
			evencount++;
		n=n>>1;
	}
	int diff=oddcount-evencount;
	if(diff<0)
		diff=-diff;
	return checkMultipleOf3(diff);
}


int main()
{
	unsigned n;
	cin>>n;
	checkMultipleOf3(n);
	return 0;
}
