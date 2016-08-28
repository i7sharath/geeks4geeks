

#include <bits/stdc++.h>

using namespace std;

int countSubArraysEvenSum(vector<int>& vec,int n)
{
	int ans=0;
	vector<int> temp(2);
	//initialize temp[0]=1 bcoz single even element is also count as subarray
	temp={1,0};
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=(abs((sum+vec[i])%2))%2;
		temp[sum]++; 
	}
	ans+=((temp[0]*(temp[0]-1))/2);
	ans+=((temp[1]*(temp[1]-1))/2);
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