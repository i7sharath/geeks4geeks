#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int  findfirstOccurrence(vector<int>& vec,int majority_elem,int start,int end)
{
	// if(start>end)
	// 	return -1;
	if(start==end)
		return start;
	int mid=(start+end)/2;
	if(vec[mid]==majority_elem)
	{
		if(mid==0 || (mid-1>0 && majority_elem > vec[mid-1] ))
			return mid;
		else
			return findfirstOccurrence(vec,majority_elem,start,mid-1);
	}
	else 
		return findfirstOccurrence(vec,majority_elem,mid+1,end);
	return 0;
}



int main()
{
	int n,majority_elem;
	cin>>n>>majority_elem;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	if(vec[n/2]!=majority_elem)
		cout<<"No Majority Element"<<endl;
	else
	{
		int firstpos=findfirstOccurrence(vec,majority_elem,0,n/2);
		if(vec[firstpos+n/2]!=majority_elem)
			cout<<"No Majority Element"<<endl;
		else
			cout<<"majority ElemEnt"<<endl;
	}
	return 0;
} 