#include <bits/stdc++.h>

using namespace std;

int checkMajority(vector<int> vec,int target,int start,int end)
{
	if(start>end)
		return end;
	int mid=start+(end-start)/2;
	if(mid>start && (vec[mid]==target && vec[mid-1]<target))
		return mid;
	else if(vec[mid]>=target)
		return checkMajority(vec,target,start,mid-1);
	else
		return checkMajority(vec,target,mid+1,end);
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
		int target;
		cin>>target;
		int firstindex=checkMajority(vec,target,0,n-1);
		if(vec[firstindex+n/2]==target)
			cout<<"true"<<endl;
		else
			cout<<"False"<<endl;
		
		testcases--;
	}
	return 0;
}