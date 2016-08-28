#include <bits/stdc++.h>

using namespace std;

int countOperationPalindrome(vector<int>& vec,int n)
{
	int ans=0;
	int i=0,j=n-1;
	while(i<=j)
	{
		if(vec[i]==vec[j])
		{
			i++;
			j--;
		}
		else if(vec[i]<vec[j])
		{
			i++;
			vec[i]+=vec[i-1];
			ans++;
		}
		else
		{
			j--;
			vec[j]+=vec[j+1];
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
		cout<<countOperationPalindrome(vec,n)<<endl;
	}
	return 0;
}