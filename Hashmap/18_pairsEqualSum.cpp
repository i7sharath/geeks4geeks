#include <bits/stdc++.h>

using namespace std;

void PairSum(vector<int>& arr,int n)
{
	map<int,vector<int> > m;
	map<int,vector<int> >::iterator it;
	vector<int> vec;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int sum=arr[i]+arr[j];
			it=m.find(sum);
			if(it==m.end())
			{
				vec.push_back(i);
				vec.push_back(j);
				m.insert(pair<int,vector<int> >(sum,vec));
				vec.clear();
			}
			else 
			{
				vec=it->second;
				cout<<"("<<arr[vec[0]]<<","<<arr[vec[1]]<<")"<<" and "<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
				vec.clear();
				return;
			}
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
		PairSum(vec,n);
	}
	return 0;
}