#include <bits/stdc++.h>

using namespace std;

int maxLenSubsequence(vector<int>& vec ,int n)
{
	vector<int> lis(n,1);

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(vec[i]==vec[j])
				continue;
			if(vec[i] > vec[j] && lis[i] < lis[j]+1)
				lis[i]=lis[j]+1;
		}
	}

	int maxlen=0;
	for(int i=0;i<n;i++)
		maxlen=max(maxlen,lis[i]);
	return maxlen;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		vector<int> lis(n);
		for(int i=0;i<n;i++)
			cin>>lis[i];
		cout<<maxLenSubsequence(lis,n)<<endl;
		testcases--;
	}
	return 0;
}