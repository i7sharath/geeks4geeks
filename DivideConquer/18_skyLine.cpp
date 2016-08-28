#include <bits/stdc++.h>

using namespace std;

void skyline(vector<int>& vec,int n)
{
	vector<int> ans;
	for(int i=0;i<n;i++)
}

int main()
{
	int n;
	cin>>n;
	vector<vector<int> > vec(n,vector<int>(3));
	for(int i=0;i<n;i++)
		cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
	skyline(vec,n);
	return 0;
}