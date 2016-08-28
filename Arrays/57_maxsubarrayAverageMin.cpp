#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

void maxSubarrayAverageMin(vector<int>& vec,int k)
{
	int start=0,i=0;
	int minsum=INT_MAX,sum=0;
	for(int i=0;i<k;i++)
		sum+=vec[i];
	minsum=min(minsum,sum);
	int s=0,e=k-1;
	for(i=k;i<vec.size();i++)
	{
		sum-=vec[start];
		sum+=vec[i];
		if(sum<minsum)
		{
			minsum=sum;
			s=start+1;
			e=i;
		}
		start++;
	}
	cout<<s+1<<" "<<e+1<<endl;
}


int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n,k;
		cin>>n>>k;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		maxSubarrayAverageMin(vec,k);
	}
	return 0;
}