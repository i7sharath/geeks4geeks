#include <bits/stdc++.h>

using namespace std;

int countInversions(vector<int>& vec)
{
	int total=0;
	int less,greater;
	for(int i=0;i<vec.size();i++)
	{
		less=0;
		greater=0;
		for(int j=0;j<i;j++)
		{
			if(vec[j]>vec[i])
				greater++;
		}
		for(int j=i+1;j<vec.size();j++)
		{
			if(vec[j]<vec[i])
				less++;
		}
		total+=greater*less;

	}
	return total;
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
		cout<<countInversions(vec)<<endl;
	}
	return 0;
}