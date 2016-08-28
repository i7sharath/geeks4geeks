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

void maxAtRightside(vector<int>& vec)
{
	int n=vec.size();
	int prev=vec[n-1];
	vec[n-1]=-1;

	for(int i=n-2;i>=0;i--)
	{
		int maxnum=max(vec[i+1],prev);
		prev=vec[i];
		vec[i]=maxnum;
	}
	return;
}

int main() {
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
	    int n;
	    cin>>n;
	    vector<int> vec(n);
	    for(int i=0;i<n;i++)
	        cin>>vec[i];
	    if(n==0)
	    	continue;
	    vector<int> temp(n);
	   maxAtRightside(vec);
	    for(int i=0;i<n;i++)
	    	cout<<vec[i]<<" ";
	   	cout<<endl;
	   	temp.clear();
	}
	return 0;
}