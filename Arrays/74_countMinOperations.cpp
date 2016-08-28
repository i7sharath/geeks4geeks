#include <bits/stdc++.h>

using namespace std;

int countMinOPerations(vector<int>& vec,int n)
{
	int ans=0;
	int zerocount=0;
	int i,j;
	while(1)
	{
		zerocount=0;
		//check if all elements in vector are 0s or not 
		for(i=0;i<n;i++)
			if(vec[i]==0)
				zerocount++;

		if(zerocount==n)
			return ans;

		//find the index of first element who value is odd
		for(i=0;i<n;i++)
		{
			if(vec[i]%2==1)
				break;
		}

		//Decrease the value of vec[i] by 1 if element is odd ,make is even and increament the operation
		for(j=i;j<n;j++)
		{
			if(vec[j]%2==1)
			{
				vec[j]--;
				ans++;
			}	
		}
		
		// all values in vector are even divide by 2 and increament the operation
		if(i==n)
		{
			for(int i=0;i<n;i++)
				vec[i]=vec[i]/2;
			ans++;	
		}

		
		
	}

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
		cout<<countMinOPerations(vec,n)<<endl;
	}
	return 0;
}