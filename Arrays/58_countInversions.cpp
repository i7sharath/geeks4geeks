#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

int countInversions(vector<int>& vec)
{
	int count=0,i=1,n=vec.size();
	int Inversions=0;
	while(i<n)
	{
		count=1;
		while(i<n)
		{
			if(vec[i]<vec[i-1])
				count++;
			else
			{
				if(count>=3)
				{
					Inversions+=(((count*(count-1)*(count-2))/6));
				}
				count=0;
				break;
			}
			i++;
		}
		i++;
	}
	if(count>=3)
		Inversions+=(((count*(count-1)*(count-2))/6));
	return Inversions;
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
		cout<<countInversions(vec)<<endl;
	}
	return 0;
}