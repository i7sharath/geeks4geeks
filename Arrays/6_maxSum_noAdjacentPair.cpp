#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;


int maxSum(vector<int>& vec)
{
	int incl=vec[0],excl=0;
	int newexcl=0;
	for(int i=1;i<vec.size();i++)
	{
		newexcl=max(incl,excl);
		incl=excl+vec[i];
		excl=newexcl;
	}	
	return max(incl,excl);

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
		cout<<maxSum(vec)<<endl;
	}
	return 0;
}