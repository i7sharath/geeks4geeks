#include <bits/stdc++.h>

using namespace std;

int Helper(vector<int>& vec,int start,int end)
{

	if(start>end)
		return 0;
	if(start==end)
		return vec[start];

	int minval=INT_MAX;
	int minIndex;

	for(int i=start;i<=end;i++)
	{
		if(vec[i]<minval)
		{
			minval=vec[i];
			minIndex=i;
		}
	}
	int mid=minIndex;
	int leftarea=Helper(vec,start,mid-1);
	int rightarea=Helper(vec,mid+1,end);
	int crossarea=(end-start+1)*vec[mid];

	return max(leftarea,max(rightarea,crossarea));
}

int largestRectangleArea(vector<int>& heights) 
{
	int n=heights.size();
    return Helper(heights,0,n-1);  
}


int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	cout<<largestRectangleArea(vec)<<endl;
	return 0;
}