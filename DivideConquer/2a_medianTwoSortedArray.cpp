#include <bits/stdc++.h>

using namespace std;

int median(vector<int>& vec1,vector<int>& vec2,int n)
{
	int i=0,j=0;
	int count=1;
	int first,second;
	while(count<=n)
	{
		if(vec1[i]<=vec2[j])
		{
			first=vec1[i];
			i++;
			count++;
		}
		else if(vec1[i]>vec2[j])
		{
			first=vec2[j];
			j++;
			count++;
		}
	}
	
	if(i<n && j<n)
	{
		if(vec1[i]<vec2[j])
			second=vec1[i];
		else
			second=vec2[j];
	}
	else if(i<n)
		second=vec1[i];
	else
		second=vec2[j];
	return (first+second)/2;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		vector<int> vec1(n);
		vector<int> vec2(n);
		for(int i=0;i<n;i++)
			cin>>vec1[i];
		for(int i=0;i<n;i++)
			cin>>vec2[i];
		cout<<median(vec1,vec2,n)<<endl;
		testcases--;
	}
	return 0;
}
