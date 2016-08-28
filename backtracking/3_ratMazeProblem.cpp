#include <bits/stdc++.h>

using namespace std;

void ratMaze(vector<vector<int> >&vec,int m,int n)
{
	vector<vector<int> > sol(m,vector<int>(n,0));
}

int main()
{
	int m,n;
	cin>>m>>n;
	vector<vector<int> > vec(m,vector<int>(n));
	for(int i=0;i<m;i++)
	{
		for(int  j=0;j<n;j++)
			cin>>vec[i][j];
	}
	ratMaze(vec);
	return 0;
}