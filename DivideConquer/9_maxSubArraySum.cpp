#include <bits/stdc++.h>

using namespace std;

int crossOver(vector<int>& vec,int l,int mid,int r)
{
	int sum=0;
	int leftsum=INT_MIN,rightsum=INT_MIN;
	for(int i=mid;i>=l;i--)
	{
		sum+=vec[i];
		leftsum=max(leftsum,sum);
	}
	sum=0;
	for(int i=mid+1;i<=r;i++)
	{
		sum+=vec[i];
		rightsum=max(rightsum,sum);
	}
	return leftsum+rightsum;
}



int maxSubarraySum(vector<int>& vec,int l,int r)
{
	if(l==r)
		return vec[l];

	int mid=l+(r-l)/2;

	int n1=maxSubarraySum(vec,l,mid);
	int n2=maxSubarraySum(vec,mid+1,r);
	int n3=crossOver(vec,l,mid,r);
	return max(n1,max(n2,n3));
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>vec[i];
	}

	cout<<maxSubarraySum(vec,0,n-1)<<endl;
	return 0;
}