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
	vector<int> left(vec.size());
	vector<int> right(vec.size());
	left[0]=0,right[vec.size()-1]=0;
	for(int i=1;i<left.size();i++)
	{
		left[i]=left[i-1]+vec[i-1];
	}
	for(int i=right.size()-2;i>=0;i--)
	{
		right[i]=right[i+1]+vec[i+1];
	}
	
	for(int i=0;i<vec.size();i++)
	{
		if(left[i]==right[i])
			return i;
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