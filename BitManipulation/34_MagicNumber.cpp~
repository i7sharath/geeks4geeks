#include <bits/stdc++.h>

using namespace std;

int MagicNumber(int n)
{
	int result=0;
	int pos=1;
	while(n>0)
	{
		if(n&1)
			result+=pow(5,pos);
		n=n>>1;
		pos++;
	}
	return result;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		cout<<MagicNumber(n)<<endl;
		testcases--;
	}
	return 0;
}
