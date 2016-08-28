
//time complexity o(n) and space o(n)

#include <bits/stdc++.h>

using namespace std;

int maxProductTriplet(vector<int>& vec)
{
	int n=vec.size();
	int min1=INT_MAX,min2=INT_MAX;
	int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(vec[i] >= max1)
		{
			max3=max2;
			max2=max1;
			max1=vec[i];
			
		}
		else if(vec[i] >=max2)
		{
			max3=max2;
			max2=vec[i];
			
		}
		else if(vec[i] >= max3)
		{
			max3=vec[i];
		}
	}

	for(int i=0;i<n;i++)
	{
		if(vec[i] <= min1)
		{
			min2=min1;
			min1=vec[i];
			
		}
		else if(vec[i]<=min2)
		{
			min2=vec[i];
		}
	}
	int ans;
	ans=max(max1*max2*max3,min1*min2*max1);
	return ans;

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
		cout<<maxProductTriplet(vec)<<endl;
	}
	return 0;
}