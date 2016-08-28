#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

void modifiyArray(vector<int>& vec,vector<int>& index)
{
	int i=0,n=vec.size();
	while(i<n)
	{
		if(i==index[i])
		{
			i++;
			continue;
		}
		while(i!=index[i])
		{
			swap(vec[i],vec[index[i]]);
			swap(index[i],index[index[i]]);
		}
		i++;
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
		vector<int> index(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		for(int i=0;i<n;i++)
			cin>>index[i];
		modifiyArray(vec,index);
		for(int i=0;i<n;i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
	return 0;
}