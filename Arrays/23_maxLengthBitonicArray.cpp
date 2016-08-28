#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int maxLengthBitonicArray(vector<int>& vec)
{
	int n=vec.size();
	vector<int> inc(n,0);
	vector<int> dec(n,0);
	for(int i=1;i<n;i++)
	{
		if(vec[i]>=vec[i-1])
			inc[i]=inc[i-1]+1;
	}
	for(int i=n-2;i>=0;i--)
	{
		if(vec[i]>=vec[i+1])
			dec[i]=dec[i+1]+1;
	}
	int maxlen=INT_MIN;
	for(int i=0;i<n;i++)
		 maxlen=max(maxlen,inc[i]+dec[i]);
	return maxlen+1;
}



int main()
{
	int testcases,n;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<maxLengthBitonicArray(vec)<<endl;
	}
	return 0;
}