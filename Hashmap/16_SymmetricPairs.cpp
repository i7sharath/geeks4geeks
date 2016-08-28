#include <bits/stdc++.h>

using namespace std;

void findSymmetricPairs(map<int,int>& m,int n)
{
	map<int,int>::iterator it;
	map<int,int>::iterator myit;
	for(it=m.begin();it!=m.end();it++)
	{
		int key=it->second;
		int val=it->first;
		myit=m.find(key);
		if(myit!=m.end())
		{
			if(myit->second==val)
			{
				cout<<val<<" "<<key<<endl;
			}
		}
		m.erase(it);
	}
	return;
}

int main()
{
	int n;
	cin>>n;
	map<int,int> m;
	for(int i=0;i<n;i++)
	{
		int key,value;
		cin>>key;
		cin>>value;
		m.insert(pair<int,int>(key,value));
	}
	findSymmetricPairs(m,n);
	return 0;
}