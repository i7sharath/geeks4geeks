
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>


using namespace std;

void checkNumberPowerOf2(unsigned int n)
{
	if(n && !(n&(n-1)))
		cout<<"Number is a power of 2"<<endl;
	else
		cout<<"Number is not a power of 2"<<endl;
	return;
}
int main()
{
	unsigned int n;
	cin>>n;
	checkNumberPowerOf2(n);
	return 0;
}