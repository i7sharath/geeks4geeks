#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSumTwoArray(vector<int>& vec1,vector<int>& vec2)
{
	int n1=vec1.size();
	int n2=vec2.size();
	int totalsum=0,i=0,j=0;
	int sum1=0,sum2=0;
	sum1+=vec1[i];
	sum2+=vec2[j];
	while(i<n1 && j<n2)
	{	
		if(vec1[i]==vec2[j])
		{
			totalsum+=max(sum1,sum2);
			i++;
			j++;
			sum1=0;
			sum2=0;
			if(i<n1)
				sum1=vec1[i];
			if(j<n2)
				sum2=vec2[j];
		}
		else if(vec1[i]<vec2[j])
		{
			i++;
			if(i<n1)
				sum1+=vec1[i];
		}
		else if(vec1[i]>vec2[j])
		{
			j++;
			if(j<n2)
				sum2+=vec2[j];
		}
	}
	i++;
	j++;
	while(i<n1)
	{
		sum1+=vec1[i];
		i++;
	}
	while(j<n2)
		sum2+=vec2[j++];
	totalsum+=max(sum1,sum2);

	return totalsum;
}




int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n1,n2;
		cin>>n1;
		vector<int> vec1(n1);
		for(int i=0;i<n1;i++)
			cin>>vec1[i];
		cin>>n2;
		vector<int> vec2(n2);
		for(int i=0;i<n2;i++)
			cin>>vec2[i];
		cout<<maxSumTwoArray(vec1,vec2)<<endl;
	}
	return 0;
}