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

int equilibriumIndex(vector<int>& vec)
{
	int sum=0,leftsum=0;
	for(int i=0;i<vec.size();i++)
		sum+=vec[i];
	for(int i=0;i<vec.size();i++)
	{
		sum-=vec[i];
		if(leftsum==sum)
			return i;
		leftsum+=vec[i];
	}

	return -1;
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
		cout<<equilibriumIndex(vec)<<endl;

	}
	return 0;
}