#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;


int maxRepeatedElement(vector<int>vec,int k)
{
	for(int i=0;i<vec.size();i++)
	{
		int ind=vec[i]%k;
		vec[ind]+=k;
	}
	int maxval=INT_MIN,index=0;

	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]>maxval)
		{
			maxval=vec[i];
			index=i;
		}
	}
	return index;
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
		cout<<maxRepeatedElement(vec,k)<<endl;
	}
	return 0;
} 