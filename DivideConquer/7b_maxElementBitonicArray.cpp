#include <bits/stdc++.h>

using namespace std;

int binarySearch(std::vector<int>& vec,int start,int end)
{
	if(start==end)
		return start;
	if(start+1==end && vec[start]>=vec[end])
		return start;
	if(start+1==end && vec[start]<vec[end])
		return end;
	int mid=start+(end-start)/2;
	if(vec[mid]>vec[mid+1] && vec[mid]>vec[mid-1])
		return mid;
	else if(vec[mid]<vec[mid+1])
		return binarySearch(vec,mid+1,end);
	else
		return binarySearch(vec,start,mid-1);
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
		for (int i = 0; i < n; ++i)
			cin>>vec[i];
		int index=binarySearch(vec,0,n-1);
		cout<<vec[index]<<endl;
		testcases--;
	}
	return 0;
}