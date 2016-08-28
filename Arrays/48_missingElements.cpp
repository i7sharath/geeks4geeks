#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

void missingNumbers(vector<int>& vec)
{
	int n=vec.size();
	vector<int> hash(100,0);
	for(int i=0;i<n;i++)
	{
		if(vec[i]<100)
			hash[vec[i]]++;
	}
	int i=0,start=0,end=0;
	while(i< 100)
	{
		if(hash[i]==1)
			i++;
		else
		{
			start=i;
			while(i<100 && hash[i]!=1)
				i++;
			end=i-1;
			if(end-start==0)
				cout<<start<<endl;
			else
			{
				cout<<start<<"-"<<end<<endl;
			}
		}
	}
	return;
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
		missingNumbers(vec);
	}
	return 0;
}