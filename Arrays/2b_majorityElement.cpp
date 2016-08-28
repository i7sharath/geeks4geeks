
//using Moore's Voting Algorithm

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	
	int n,t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		vector<int> num(n);
		for(int j=0;j<n;j++)
		{
			cin>>num[j];
		}
		//find the candidate for majority element
		int major_index=0,count=1;
		for(int j=1;j<n;j++)
		{
			if(num[major_index]==num[j])
				count++;
			else
				count--;
			if(count==0)
			{
				major_index=j;
				count=1;
			}
		}
		// check if candidate is a majority element or not
			count=0;
			for(int j=0;j<n;j++)
			{
				if(num[j]==num[major_index])
					count++;
			}
			if(count > ceil(n/2))
				cout<<num[major_index]<<endl;
			else
				cout<<"NO Majority Element"<<endl;
		
	}
	return 0;
}


