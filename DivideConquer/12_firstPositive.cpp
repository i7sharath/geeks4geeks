#include <bits/stdc++.h>

using namespace std;

int function(int x)
{
	return (x*x -10*x -20);
}

int binarySearch(int start,int end)
{
	if(start>end)
		return -1;
	if(start==end)
		return start;
	int mid=start+(end-start)/2;
	if(mid<end && function(mid)<0 && function(mid+1)>=0)
		return mid+1;
	else if(mid>start && function(mid)>=0 && function(mid-1)<0)
		return mid;

	else if(function(mid)<=0)
		return binarySearch(mid+1,end);
	else
		return binarySearch(start,mid-1);
}

int findPositive()
{
	if(function(0)==0)
		return 0;
	int i=1;
	while(function(i)<=0)
		i=i*2;
	return binarySearch(i/2,i);
}



int main()
{
	cout<<findPositive()<<endl;
	return 0;
}