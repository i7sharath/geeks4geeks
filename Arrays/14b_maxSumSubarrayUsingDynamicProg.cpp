#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;


int MaxSum(vector<int> vec)
{
	int maxsum=vec[0],currsum=vec[0];
	for(int i=1;i<vec.size();i++)
	{
		currsum=max(vec[i],currsum+vec[i]);
		maxsum=max(currsum,maxsum);
	}
	return maxsum;
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
		cout<<MaxSum(vec)<<endl;

	}
	return 0;
}