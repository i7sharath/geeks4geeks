#include <bits/stdc++.h>

using namespace std;

void auxfunc(map<string,string>& m,int n)
{
	string key;
	map<string,string> :: iterator it;
	map<string,string>::iterator myit;
	for(it=m.begin();it!=m.end();it++)
	{
		myit=m.find(it->second);
		if(myit!=m.end())
			break;
	}
	key=it->second;
	cout<<it->first<<"->"<<it->second<<endl;
	while(1)
	{
		it=m.find(key);
		if(it==m.end())
			break;
		else
		{
			cout<<it->first<<"->"<<it->second<<endl;
			key=it->second;
		}

	}
	return;
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n;
		cin>>n;
		map<string,string> m;
		map<string,string> :: iterator it;
		for(int i=0;i<n;i++)
		{
			string key,value;
			cin>>key;
			cin>>value;
			m.insert(pair<string,string>(key,value));
		}
		auxfunc(m,n);
	}
	return 0;
}