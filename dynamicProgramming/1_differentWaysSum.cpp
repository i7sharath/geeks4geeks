#include <bits/stdc++.h>

using namespace std;

int combinationSum(int n)
{
	vector<int> dp(n+1);
	dp[0]=dp[1]=dp[2]=1;
	dp[3]=2;
	for(int i=4;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-3]+dp[i-4];
	}
	return dp[n];
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n;
		cin>>n;
		cout<<combinationSum(n)<<endl;
	}
	return 0;
}