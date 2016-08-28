#include <bits/stdc++.h>

using namespace std;

int setBits(int x,int l,int r,int y)
{
	for(int i=l;i<=r;i++)
	{
		int mask=1<<(i-1);
		if(y & mask)
			x|=mask;
	}
	return x;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int x,y,l,r;
		cin>>x>>l>>r>>y;
		cout<<setBits(x,l,r,y)<<endl;
		testcases--;
	}
	return 0;
}
