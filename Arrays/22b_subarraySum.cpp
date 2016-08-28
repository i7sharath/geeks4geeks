#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void subarraySum(vector<int> vec,int sum)
{
	int maxsum=vec[0],start=0;
	for(int i=1;i<=vec.size();i++)
	{
		while(maxsum >sum && start<i-1)
		{
			maxsum=maxsum- vec[start];
			start++;
		}
		if(maxsum==sum)
		{
			cout<<"index is between "<<start<<" and "<<i-1<<endl;
			return;
		}
		if(i<vec.size())
			maxsum+=vec[i];

	}
	cout<<"NO subarray found"<<endl;
}



int main()
{
	int testcases,n;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		int sum;
		cin>>sum;
		subarraySum(vec,sum);
	}
	return 0;
}