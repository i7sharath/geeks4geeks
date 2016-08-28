#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool pythagoreanTriplet(vector<int>& vec)
{
	int n=vec.size();
	int l,r;
	sort(vec.begin(),vec.end());
	for(int i=0;i<n-2;i++)
	{
		l=i+1;
		r=l+1;
		while(r<n)
		{
			int lhs=vec[i]*vec[i]+ vec[l]*vec[l];
			int rhs=vec[r]*vec[r];
			if(lhs==rhs)
			{
				return true;
			}
			else if(lhs<rhs)
			{	
				l++;
				if(l==r)
					r++;
			}
			else
				r++;

		}
	}
	return false;
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
		bool ans=pythagoreanTriplet(vec);
		if(ans==true)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}