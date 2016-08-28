#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void commonElementThreeArray(vector<int>& vec1,int n1,vector<int>& vec2,int n2,vector<int>& vec3,int n3)
{
	vector<int> ans;
	int i=0,j=0,k=0;
	while(i<n1 && j<n2 && k<n3)
	{
		if(vec1[i]==vec2[j] && vec2[j]==vec3[k])
		{
			ans.push_back(vec1[i]);
			i++;
			j++;
			k++;
		}
		else
		{
			int minval=min(vec1[i],min(vec2[j],vec3[k]));
			if(vec1[i]==minval)
				i++;
			if(vec2[j]==minval)
				j++;
			if(vec3[k]==minval)
				k++;
		}
		
	}
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return;
}


int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n1,n2,n3;
		cin>>n1;
		vector<int> vec1(n1);
		for(int i=0;i<n1;i++)
			cin>>vec1[i];
		cin>>n2;
		vector<int> vec2(n2);
		for(int i=0;i<n2;i++)
			cin>>vec2[i];
		cin>>n3;
		vector<int> vec3(n3);
		for(int i=0;i<n3;i++)
			cin>>vec3[i];
		commonElementThreeArray(vec1,n1,vec2,n2,vec3,n3);
	}
	return 0;
}