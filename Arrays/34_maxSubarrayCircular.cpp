#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int kadane(vector<int>& vec)
{
	int maxsum=INT_MIN,currsum=0;
	for(int i=0;i<vec.size();i++)
	{
		currsum=max(vec[i],currsum+vec[i]);
		maxsum=max(maxsum,currsum);
	}
	return maxsum;
}

int maxSubarrayCircular(vector<int>& vec)
{
	int maxsum=INT_MIN;
	maxsum=kadane(vec);

	int total=0;
	for(int i=0;i<vec.size();i++)
	{
		total+=vec[i];
		vec[i]=-vec[i];
	}
	int max2=kadane(vec);
	max2=total+max2;
	maxsum=max(maxsum,max2);
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
		cout<<maxSubarrayCircular(vec)<<endl;
	}
	return 0;
} 