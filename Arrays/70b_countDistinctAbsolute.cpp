#include <bits/stdc++.h>

using namespace std;

int countDistinctAbsolute(vector<int>& vec)
{
	int n=vec.size();
	int count=n;
	int i=0,j=n-1;
	while(i<j)
	{
		//remove duplicates from left side
		while(i<j && vec[i]==vec[i+1])
		{
			count--;
			i++;
		}

		//remove duplicates from right side
		while(i<j && vec[j]==vec[j-1])
		{
			count--;
			j--;
		}

		while(i<j)
		{
			int sum=vec[i]+vec[j];
			if(sum==0)
			{
				count--;
				i++;
				j--;
			}
			else if(sum<0)
				i++;
			else
				j--;
		}


	}
	return count;
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<countDistinctAbsolute(vec)<<endl;
	}
	return 0;
}