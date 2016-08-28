#include <bits/stdc++.h>

using namespace std;

int nextSparseNumber(int n)
{
	vector<int> vec;
	int num=n,ans=0;
	
	while(num>0)
	{
		vec.push_back(num%2);
		num/=2;
	}
	
	vec.push_back(0);

	int last_Ind=0;
	for(int i=1;i<vec.size()-1;i++)
	{
		if(vec[i]==1 && vec[i-1]==1 && vec[i+1]!=1)
		{
			vec[i+1]=1;
			for(int j=i;j>=last_Ind;j--)
				vec[j]=0;
			last_Ind=i+1;
		}
	}
		
	for(int i=0;i<vec.size();i++)
	{
		ans+=(vec[i]*(1<<i));
	}
	return ans;
	
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		int n;
		cin>>n;
		cout<<nextSparseNumber(n)<<endl;
		testcases--;
	}
	return 0;
}
