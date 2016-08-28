#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

void maxSubarrayAverage(vector<int>& vec,int k)
{
	if(vec.size()<k)
	{
		cout<<"array start from index:-1"<<endl;
		cout<<"average sum:0"<<endl;
		return;
	}
	int sum=0,start=0;
	for(int i=0;i<k;i++)
		sum+=vec[i];
	int index=0,maxsum=sum;

	for(int i=k;i<vec.size();i++)
	{
		sum+=vec[i];
		sum-=vec[start++];
		if(sum>maxsum)
		{
			maxsum=sum;
			index=start;
		}
	}
	cout<<"array start from index:"<<index<<endl;
	cout<<"average sum:"<<maxsum/k<<endl;
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
		int k;
		cin>>k;
		maxSubarrayAverage(vec,k);
	}
	return 0;
}