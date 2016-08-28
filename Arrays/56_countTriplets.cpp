#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int countTriplets(vector<int>& vec,int x)
{
	int sum,count=0;
	int i=0,j=0,k=0;
	int n=vec.size();
	sort(vec.begin(),vec.end());
	for(i=0;i<n-2;i++)
	{
		k=n-1;
		for(j=i+1;j<n;j++)
		{
			while((vec[i]+vec[j]+vec[k])>=x && k>j)
				k--;
			if(k==j)
				break;
			count+=(k-j);	

		}
		
	}
	return count;
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
		int sum;
		cin>>sum;
		cout<<countTriplets(vec,sum)<<endl;
	}
	return 0;
}