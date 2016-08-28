#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void  saggregateEvenOdd(vector<int>& vec)
{
	int count=0;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]%2==0)
			swap(vec[i-count],vec[i]);
		else
			count++;
	}
	return ;
}


int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	saggregateEvenOdd(vec);
	for(int i=0;i<n;i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	return  0;
}