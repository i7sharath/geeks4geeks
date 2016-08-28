#include <bits/stdc++.h>
	
using namespace std;

int sumBitDiff(vector<int>& vec,int n)
{
	int sum=0,count;
	for(int i=0;i<32;i++)
	{
		count=0;
		for(int j=0;j<n;j++)
		{
			if(vec[j] & (1<<i))
				count++;
		}
		sum+=(count*(n-count)*2);
	}
	return sum;
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
		cout<<sumBitDiff(vec,n)<<endl;
		testcases--;
	}
	return 0;
}
