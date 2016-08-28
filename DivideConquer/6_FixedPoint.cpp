#include <bits/stdc++.h>

using namespace std;

int findFixedPoint(vector<int>& vec,int start,int end)
{
	if(start>end)
		return -1;
	int mid=start+(end-start)/2;
	if(vec[mid]==mid)
		return mid;
	else if(vec[mid]<mid)
		return findFixedPoint(vec,mid+1,end);
	else
		return findFixedPoint(vec,start,mid-1);
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
		cout<<findFixedPoint(vec,0,n-1)<<endl;
		testcases--;
	}
	return 0;
}