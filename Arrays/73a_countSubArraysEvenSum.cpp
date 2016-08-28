#include <bits/stdc++.h>

using namespace std;

int countSubArraysEvenSum(vector<int>& vec,int n)
{
	int ans=0,sum=0;
	for(int i=0;i<n;i++)
	{
		sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=vec[j];
			if(sum%2==0)
				ans++;
		}
	}
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
		cout<<countSubArraysEvenSum(vec,n)<<endl;
	}
	return 0;
}