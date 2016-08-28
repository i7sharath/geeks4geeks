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

void sortedSubsequenceThree(vector<int>& vec)
{
	vector<int> smaller(vec.size());
	vector<int> greater(vec.size());
	
	int small_index=0,greater_index=vec.size()-1;
	smaller[0]=-1,greater[vec.size()-1]=-1;
	
	for(int i=1;i<vec.size();i++)
	{
		if(vec[i]<=vec[small_index])
		{
			small_index=i;
			smaller[i]=-1;
		}
		else
			smaller[i]=small_index;
	}

	for(int i=vec.size()-2;i>=0;i--)
	{
		if(vec[i]>=vec[greater_index])
		{
			greater_index=i;
			greater[i]=-1;
		}
		else
			greater[i]=greater_index;
	}

	for(int i=0;i<vec.size();i++)
	{
		if(smaller[i]!=-1 && greater[i]!=-1)
		{
			cout<<vec[smaller[i]]<<" "<<vec[i]<<" "<<vec[greater[i]]<<endl;
			return;
		}
	}
	cout<<"No such triplet"<<endl;
	return;
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
		sortedSubsequenceThree(vec);
	}
	return 0;
}