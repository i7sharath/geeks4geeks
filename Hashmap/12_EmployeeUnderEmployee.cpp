#include <bits/stdc++.h>

using namespace std;

void auxfunc(map<char,char> m,int n)
{
	map<char,int> mymap;
	map<char,char>::iterator it;
	map<char,int> :: iterator myit;
	for(it=m.begin();it!=m.end();it++)
	{
		int key=it->first;
		mymap.insert(pair<char,int>(key,0));
		
	}
	for(it=m.begin();it!=m.end();it++)
	{
		int val=it->second;
		myit=mymap.find(val);
		if(myit==mymap.end())
			mymap.insert(pair<char,int>(val,1));
		else
			myit->second+=1;
	}
	for(myit=mymap.begin();myit!=mymap.end();myit++)
	{
		cout<<myit->first<<" : ";
		cout<<myit->second<<endl;
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
		map<char,char> m;
		map<char,char> :: iterator it;
		for(int i=0;i<n;i++)
		{
			char key,value;
			cin>>key;
			cin>>value;
			m.insert(pair<char,char>(key,value));
		}
		auxfunc(m,n);
	}
	return 0;
}