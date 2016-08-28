#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
	int arr1[]={2,-1,7,-1,-1,10,-1};
	int arr2[]={5,8,12,14};
	int m=sizeof(arr1)/sizeof(arr1[0]);
	int n=sizeof(arr2)/sizeof(arr2[0]);
	int i=m-1,j=m-1;
	//shift the arr1 to the end
	for(i=m-1;i>=0;i--)
	{
		if(arr1[i]!=-1)
		{
			swap(arr1[i],arr1[j]);
			j--;
		}
	}
	int p=n,q=0,k=0;

	while(p< m && j<n)
	{
		if(arr1[p]<=arr2[q])
		{
			arr1[k]=arr1[p];
			k++;
			p++;
		}
		else
		{
			arr1[k]=arr2[q];
			k++;
			q++;
		}
	}
	while(p<m)
	{
		arr1[k]=arr1[p];
		k++;
		p++;
	}
	while(q<n)
	{
		arr1[k]=arr2[q];
		k++;
		q++;
	}
	for(int k=0;k<m;k++)
		cout<<arr1[k]<<" ";
	cout<<endl;

	return 0;
}