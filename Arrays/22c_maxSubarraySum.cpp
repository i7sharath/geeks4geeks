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
	if(sum==0)
		return "No subarray found"<<endl;
	int i=0,j=0;
	int currsum=0;
	while(i<vec.size() && j<vec.size())
	{
		if(currsum<sum)
		{
			currsum+=vec[j];
			j++;
		}
		else if(currsum >sum)
		{
			currsum-=vec[i];
			i++;
		}
		if(currsum==sum)
		{
			cout<<i<<"and"<<j-1<<endl;
			return;
		}
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