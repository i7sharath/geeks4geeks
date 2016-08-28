#include <bits/stdc++.h>

using namespace std;

int maxLengthEqualZeroOnes(vector<int>& vec,int n)
{
	int maxlen=INT_MIN;
	int wl=0,wr=0,zerocount=0,onecount=0;
	while(wr<n)
	{
		if(vec[wr]==0)
			zerocount++;
		else
			onecount++;
		if(zerocount==onecount)
		{
			
			maxlen=max(maxlen,wr-wl+1);
		}
		wr++;
	}
	wr=n-1;
	while(wl<n)
	{
		if(vec[wl]==0)
			zerocount--;
		else
			onecount--;
		if(zerocount==onecount)
		{
			maxlen=max(maxlen,wr-wl);
		}
		wl++;
	}
	return maxlen;
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<maxLengthEqualZeroOnes(vec,n)<<endl;
	}
	return 0;
}