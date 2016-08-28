#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& vec,int year,int start,int end)
{
	if(start>end)
		return 0;
	int left=year*vec[start]+maxProfit(vec,year+1,start+1,end);
	int right=year*vec[end]+maxProfit(vec,year+1,start,end-1);
	return max(left,right);
}


int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	int year=1;
	cout<<maxProfit(vec,year,0,n-1)<<endl;
	return 0;
}