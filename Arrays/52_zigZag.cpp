#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

void zigZag(vector<int>& vec)
{
	int flag=0;
	for(int i=0;i<vec.size()-1;i++)
	{
		if(flag==0)
		{
			if(vec[i]>vec[i+1])
				swap(vec[i],vec[i+1]);
			flag=1;
		}	
		else
		{	
			if(vec[i]<vec[i+1])
				swap(vec[i],vec[i+1]);
			flag=0;
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
		zigZag(vec);
		for(int i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
	return 0;
}