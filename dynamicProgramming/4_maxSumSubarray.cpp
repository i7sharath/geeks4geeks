#include <bits/stdc++.h>

using namespace std;

int maxSumSubarray(vector<int>& vec,int n)
{
	int maxsum=INT_MIN;
	int currsum=0;
	for(int i=0;i<n;i++)
	{
		currsum=max(vec[i],currsum+vec[i]);
		maxsum=max(maxsum,currsum);
	}
	return maxsum;
}


int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<maxSumSubarray(vec,n)<<endl;	
		testcases--;
	}
	return 0;
}