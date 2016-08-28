#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int maximumDifference(vector<int>& vec)
{
	int diff=0;
	int minvalue=vec[0];
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i]<minvalue) 
		{
			minvalue=vec[i];
		}
		else if(vec[i]>minvalue)
		{
			diff=(vec[i]-minvalue);
		}
		
	}
	return diff;
}


int main()
{
	int n,testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<maximumDifference(vec)<<endl;
	}
	return 0;
}