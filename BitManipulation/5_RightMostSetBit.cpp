
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>


using namespace std;

void RightMostSetBit(unsigned int n)
{
	if(n==0)
	{
		cout<<"set bit is not exist"<<endl;
		return;
	}
	int index=1;
	while(n>0)
	{
		if(n&1)
			break;
		n=n>>1;
		index++;
	}
	cout<<index<<endl;
	return;

}

int main()
{
	unsigned int n;
	cin>>n;
	RightMostSetBit(n);
	return 0;
}