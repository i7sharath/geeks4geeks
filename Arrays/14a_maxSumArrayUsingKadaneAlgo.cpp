#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <climits>
#include <cstdint>

using namespace std;


int MaxSum(vector<int> vec)
{
	int max=0,curr=0;
	for(int i=0;i<vec.size();i++)
	{
		curr=curr+vec[i];
		if(curr <0)
			curr=0;
		else if(curr > max)
			max=curr;
	}
	return max;
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
		int sum=MaxSum(vec);

		//Handling when all the elements in an array is negative ,returns 0
		if(sum==0)
		{
			sum=INT_MIN;
			for(int i=0;i<n;i++)
			{
				if(vec[i]>sum)
					sum=vec[i];
			}
		}
		cout<<sum<<endl;

	}
	return 0;
}