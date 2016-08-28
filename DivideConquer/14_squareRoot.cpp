#include <bits/stdc++.h>

using namespace std;

int sqrtFloor(long long int n,long long int start,long long int end)
{
	if(start>end)
		return end;

	long long int mid=start+(end-start)/2;
	if(mid*mid==n)
		return mid;
	else if(mid*mid < n)
		return sqrtFloor(n,mid+1,end);
	else
		return sqrtFloor(n,start,mid-1);
}


int main()
{
	int n;
	cin>>n;
	if(n==0)
		return 0;
	if(n<=3)
		return 1;
	cout<<sqrtFloor(n,1,n)<<endl;
	return 0;
}