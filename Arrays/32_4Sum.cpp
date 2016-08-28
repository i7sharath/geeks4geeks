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

struct pairSum
{
	int first;
	int second;
	int sum;
};
//typedef struct pairSum PairSum;

bool compare(pairSum lhs,pairSum rhs)
{
	return lhs.sum<rhs.sum;
}


void fourSum(vector<int>& vec,int x)
{
	int n=vec.size();
	int auxsize=(n*(n-1))/2;
	vector<pairSum> auxarr(auxsize);

	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			auxarr[k].first=i;
			auxarr[k].second=j;
			auxarr[k].sum=vec[i]+vec[j];
			k++;
		}
	}
	sort(auxarr.begin(),auxarr.end(),compare);

	int i=0,j=auxsize-1;
	while(i<j)
	{
		if(auxarr[i].sum+auxarr[j].sum==x)
		{
			if(auxarr[i].first!=auxarr[j].first && auxarr[i].first!=auxarr[j].second && auxarr[i].second!=auxarr[j].first && auxarr[i].second!=auxarr[j].first)
			{
				cout<<vec[auxarr[i].first]<<" "<<vec[auxarr[i].second]<<" "<<vec[auxarr[j].first]<<" "<<vec[auxarr[j].second]<<endl;
				return;
			}
		}
		else if(auxarr[i].sum + auxarr[j].sum < x)
			i++;
		else
			j--;
	}

}



int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n,x;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cin>>x;
		fourSum(vec,x);
	}
	return 0;
}