#include <bits/stdc++.h>

using namespace std;

int strictIncreasinbgSubArrays(vector<int>& vec)
{
	int n=vec.size();
	if(n==0 || n==1)
		return 0;
	int total=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(vec[j]>vec[j-1])
				total++;
			else
				break;
		}
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
		cout<<strictIncreasinbgSubArrays(vec)<<endl;
	}
	return 0;
}