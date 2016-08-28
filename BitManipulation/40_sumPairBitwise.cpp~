#include <bits/stdc++.h>

using namespace std;

int SumPairBitwise(vector<int>& vec,int n)
{
	int count,ans=0;
	for(int i=0;i<32;i++)
	{
		count=0;
		for(int j=0;j<n;j++)
		{
			if(vec[j] & (1<<i))
				count++;
		}
		ans+=(1<<i)*((count*(count-1))/2);
	}
	return ans;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<SumPairBitwise(vec,n)<<endl;
	}
	return 0;
}
