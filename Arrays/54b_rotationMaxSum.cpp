/* Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we
 want. Return the maximum possbile of summation of i*arr[i].*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int rotationMaxSum(vector<int>& vec)
{
	int n=vec.size(),maxsum=INT_MIN;
	int sum=0,nextsum=0;
	for(int i=0;i<n;i++)
	{
		nextsum+=(i*vec[i]);
		sum+=vec[i];
	}
	maxsum=nextsum;
	for(int i=1;i<n;i++)
	{
		nextsum=nextsum-sum + n*vec[i-1];
		maxsum=max(maxsum,nextsum);
	}
	return maxsum;
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
		cout<<rotationMaxSum(vec)<<endl;
	}
	return 0;
}