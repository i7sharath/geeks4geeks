#include <bits/stdc++.h>

using namespace std;

void findMinMax(vector<int>& vec,int start,int end,int &minval,int &maxval)
{
	if(start>end)
		return ;
	if(start==end)
	{
		minval=vec[start];
		maxval=minval;
		return ;
	}
	else if(start+1==end)
	{
		minval=min(vec[start],vec[end]);
		maxval=max(vec[start],vec[end]);
		return ;
	}

	int minval1,minval2,maxval1,maxval2;
	int mid=start+(end-start)/2;
	findMinMax(vec,start,mid,minval1,maxval1);
	findMinMax(vec,mid+1,end,minval2,maxval2);

	minval=min(minval1,minval2);
	maxval=max(maxval1,maxval2);
	return;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		int minval,maxval;
		findMinMax(vec,0,n-1,minval,maxval);
		cout<<maxval<<" "<<minval<<endl;
		testcases--;
	}
	return 0;
}