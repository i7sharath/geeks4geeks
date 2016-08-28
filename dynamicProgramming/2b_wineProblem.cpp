#include <bits/stdc++.h>

using namespace std;



int maxProfit(vector<int>& vec,int start,int end,vector<vector<int> >& cache,int n)
{
	if(start>end)
		return 0;

	if(cache[start][end]!=-1)
		return cache[start][end];

	int year=n-(end-start+1)+1;
	int left=year*vec[start]+maxProfit(vec,start+1,end,cache,n);
	int right=year*vec[end]+maxProfit(vec,start,end-1,cache,n);
	cache[start][end]=max(left,right);
	return cache[start][end];
}



int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	vector<vector<int> > cache(n,vector<int>(n,-1));
	for(int i=0;i<n;i++)
		cin>>vec[i];
	cout<<maxProfit(vec,0,n-1,cache,n)<<endl;
	return 0;
}