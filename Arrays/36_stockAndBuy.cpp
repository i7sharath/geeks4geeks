#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>

using namespace std;

int maxProfit(vector<int>& vec)
{
	if(vec.size()==0)
		return 0;
	int maxsum=0;
	int i=0,j=1;
	while(j<vec.size() && i<j)
	{
		if(vec[j]>=vec[j-1])
			j++;
		else if(j==i+1 && vec[j]<vec[j-1])
		{
			i=j;
			j++;
		}
		else
		{
			cout<<"buy on :"<<i<<" "<<"   sell on :"<<j-1<<endl;
			maxsum=max(maxsum,vec[j-1]-vec[i]);
			i=j;
			j++;
		}
	}
	maxsum=max(maxsum,vec[j-1]-vec[i]);
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
		cout<<maxProfit(vec)<<endl;
	}
	return 0;
}