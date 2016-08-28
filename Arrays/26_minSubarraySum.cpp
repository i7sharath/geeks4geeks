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


int minSubarraySum(vector<int>& vec,int x)
{
	if(vec.size()==0)
		return 0;
	int start=0,end=0,minlen=INT_MAX,currsum=0;
	while(end<vec.size())
	{
		while(currsum<x && end<vec.size())
		{
			currsum+=vec[end];
			end++;
		}
		while(currsum>=x && start<vec.size())
		{
			minlen=min(minlen,end-start);
			currsum-=vec[start];
			start++;
		}
	}
	return minlen;
}



int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n,x;
		cin>>n>>x;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<minSubarraySum(vec,x)<<endl;
	}
	return 0;
}