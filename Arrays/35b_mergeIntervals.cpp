#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>

using namespace std;

bool compareintervals(vector<int> vec1,vector<int> vec2)
{
	return vec1[0]>vec2[0]?0:1;
}

void mergeIntervals(vector<vector<int> >& vec)
{
	sort(vec.begin(),vec.end(),compareintervals);
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i-1][1] >=vec[i][0])
		{
			if(vec[i-1][1]<=vec[i][1])
			{
				vec[i-1][1]=vec[i][1];
			}	
			vec.erase(vec.begin()+i,vec.begin()+i+1);
			i--;
		}
	}
	return;
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int i=0;i<testcases;i++)
	{
		int n;
		cin>>n;
		vector<vector<int> > vec;
		vector<int> subvec(2);
		for(int i=0;i<n;i++)
		{
			cin>>subvec[0]>>subvec[1];
			vec.push_back(subvec);
		}
	
		mergeIntervals(vec);
		for(int i=0;i<vec.size();i++)
		{
			for(int j=0;j<2;j++)
				cout<<vec[i][j]<<" ";
		}
		cout<<endl;

	}
	return 0;
} 