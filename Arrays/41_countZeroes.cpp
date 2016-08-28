#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int bs(vector<int> &vec, int s, int e)
{
	if(s>e)
		return -1;
	
	int mid=(s+e)/2;
	if((mid==s && vec[mid]==0) || (vec[mid]==0 && vec[mid-1]==1))
		return mid;
	
	else if(vec[mid]==1)
		return bs(vec,mid+1,e);
		
	else	
		return bs(vec,s,mid-1);
}


int binarysearch(vector<int>& vec,int start,int end)
{
	
	if(start==end && vec[start]==0)
		return start;
	else if(start==end && vec[start]==1)
		return start+1;
	else
	{
		int mid=(start+end)/2;
		if(vec[mid]==0 && start==mid)
			return start;
		if(vec[mid]==0)
			return binarysearch(vec,start,mid-1);
		else
			return binarysearch(vec,mid+1,end);
	}
}

int countZeroes(vector<int>& vec,int start,int end)
{
	int n=vec.size();
	int index=bs(vec,0,n-1);
	if(index==-1)
		cout<<"0"<<endl;
	else
		cout<<n-index<<endl;
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
		countZeroes(vec,0,n-1);
	}
	return 0;
}