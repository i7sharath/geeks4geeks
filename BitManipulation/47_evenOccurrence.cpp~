#include <bits/stdc++.h>

using namespace std;

void evenOccurrence(vector<int>& vec,int n)
{
	long long int xorval;
	long long int pos;
	for(int i=0;i<n;i++)
	{
		pos=1<<vec[i];
		xorval^=pos;
	}	
	
	for(int i=0;i<n;i++)
	{
		pos=1<<vec[i];
		if(!(pos & xorval))
		{
			cout<<vec[i]<<" ";
			xorval^=pos;
		}
	}
	return ;
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
		for(int i=0;i<n;i++)
			cin>>vec[i];
		evenOccurrence(vec,n);
		testcases--;
	}
	return 0;
}
