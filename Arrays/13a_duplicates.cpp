#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void duplicateElements(vector<int> vec)
{
	map<int,int> m;
	map<int,int>::iterator it;
	for(int i=0;i<vec.size();i++)
	{
		it=m.find(vec[i]);
		if(it==m.end())
			m.insert(pair<int,int>(vec[i],1));
		else
				cout<<it->first<<" ";
	}
	cout<<endl;
	return;
}


int main()
{
	int n,testcases;
	cin>>testcases>>n;
	vector<int> vec(n+2);
	for(int i=0;i<n+2;i++)
		cin>>vec[i];
	duplicateElements(vec);
	
	return  0;
}