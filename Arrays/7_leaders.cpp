#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

void findLeaders(vector<int>& vec)
{
	int leader=vec[vec.size()-1];
	cout<<leader<<" ";
	
	for(int i=vec.size()-2;i>=0;i--)
	{
		if(vec[i] > leader)
		{
			leader=vec[i];
			cout<<leader<<" ";
		}
	}
	cout<<endl;
	return;
}


int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	findLeaders(vec);
	return 0;
}