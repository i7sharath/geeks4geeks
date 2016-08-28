#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int maxIndexDiff(vector<int>& vec)
{
	if(vec.size()==1)
		return 0;
	vector<int> leftmin(vec.size());
	vector<int> rightmax(vec.size());
	leftmin[0]=vec[0];
	rightmax[vec.size()-1]=vec[vec.size()-1];

	for(int i=1;i<vec.size();i++)
		leftmin[i]=min(vec[i],leftmin[i-1]);
	for(int i=vec.size()-2;i>=0;i--)
		rightmax[i]=max(vec[i],rightmax[i+1]);

	int maxdiff=-1,minIndex=0,maxIndex=0;
	while((minIndex < leftmin.size()) && (maxIndex < rightmax.size()))
	{
		if(leftmin[minIndex] < rightmax[maxIndex])
		{
			maxdiff=max(maxdiff,maxIndex-minIndex);
			maxIndex++;
		}
		else
			minIndex++;
	}
	return maxdiff;
}


int main()
{
	int testcases,n;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<maxIndexDiff(vec)<<endl;

	}
	return 0;
}