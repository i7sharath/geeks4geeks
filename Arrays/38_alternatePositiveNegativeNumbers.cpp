#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>

using namespace std;


void partition(vector<int>& vec,int key)
{
	int n=vec.size();
	int i=0,j=n-1;
	while(i<j)
	{
		while(vec[i]<key && i<j)
			i++;
		while(j>i && vec[j]>key)
			j--;
		if(i>j)
			break;
		swap(vec[i],vec[j]);
		i++;
		j--;
	}
	reverse(vec.begin(),vec.end());
	int pos=0,neg=0;
	i=0;
	while(i <n)
	{
		if(vec[i]<0)
		{
			neg=i;
			break;
		}
		i++;


	}
	for(int pos=1;pos<neg;pos++)
	{
		if(pos%2==1 && neg<n)
		{
			swap(vec[pos],vec[neg]);
			neg++;
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
		partition(vec,0);
		for(int i=0;i<n;i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
	return 0;
} 