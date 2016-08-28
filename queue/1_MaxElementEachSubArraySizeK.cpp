#include <bits/stdc++.h>

using namespace std;

void maxElementEachSubArray(vector<int>& vec,int n,int k)
{
	int maxval;
	for(int i=0;i<=n-k;i++)
	{
		maxval=vec[i];
		for(int j=1;j<k;j++)
		{
			maxval=max(maxval,vec[i+j]);
		}
		cout<<maxval<<" ";
	}
	cout<<endl;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n,k;
		cin>>n>>k;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		maxElementEachSubArray(vec,n,k);
		testcases--;	
	}
	return 0;	
}