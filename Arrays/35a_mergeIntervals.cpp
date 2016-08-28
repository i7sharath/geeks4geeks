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
	int n=vec.size();
	sort(vec.begin(),vec.end(),compareintervals);
	stack<vector<int> > st;
	st.push(vec[0]);
	for(int i=1;i<n;i++)
	{
		vector<int> temp=st.top();
		if(temp[1]>=vec[i][0] && temp[1]<=vec[i][1])
		{
			temp[1]=vec[i][1];
			st.pop();
			st.push(temp);
		}
		else
			st.push(vec[i]);
	}
	vec.clear();
	while(!st.empty())
	{
		vector<int> temp=st.top();
		st.pop();
		vec.push_back(temp);
	}
	reverse(vec.begin(),vec.end());
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