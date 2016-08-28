#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

void PrintDuplicates(string s)
{
	map<char,int> m;
	map<char,int>:: iterator it;
	for(int i=0;i<s.length();i++)
	{
		it=m.find(s[i]);
		if(it==m.end())
		{
			m.insert(pair<char,int>(s[i],1));
		}
		else
			it->second+=1;
	}
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second >1)
			cout<<it->first<<":"<<it->second<<endl;
	}
	cout<<endl;
	return;
}

int main()
{
	
	string s;
	getline(cin,s,'\n');
	PrintDuplicates(s);
	return 0;
}