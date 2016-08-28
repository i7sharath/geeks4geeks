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

int smallestMissing(vector<int>& vec,int start,int end)
{
	if(start!=vec[start])
		return start;
	int mid=(start+end)/2;
	if(vec[mid]>mid)
		return smallestMissing(vec,start,mid);
	else
		return smallestMissing(vec,mid+1,end);

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
		cout<<smallestMissing(vec,0,vec.size()-1)<<endl;

	}
	return 0;
}