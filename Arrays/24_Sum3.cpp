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


int Sum3(vector<int>& vec,int target)
{
	sort(vec.begin(),vec.end());
	int l=0,r=0;
	for(int i=0;i<vec.size()-2;i++)
	{
		l=i+1;
		r=vec.size()-1;
		while(l<r)
		{
			if(vec[i]+vec[l]+vec[r]==target)
				return 1;
			else if(vec[i]+vec[l]+vec[r]<target)
				l++;
			else
				r--;
		}
	}
	return 0;

}


int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n,target;
		cin>>n>>target;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<Sum3(vec,target)<<endl;
	}
	return 0;
}