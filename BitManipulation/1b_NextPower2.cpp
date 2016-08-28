#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

void NextPower2(unsigned int n)
{
	if(n && ((n&(n-1))==0))
	{
		cout<<n<<endl;
		return;
	}	
	int count=0,ans=0;
	while(n>0)
	{
		count++;
		n=n>>1;
	}
	ans=pow(2,count );
	cout<<ans<<endl;
	return;
}

int main()
{
	unsigned int n;
	cin>>n;
	NextPower2(n);
	return 0;
}