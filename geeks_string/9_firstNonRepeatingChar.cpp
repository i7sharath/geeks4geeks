#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

void firstNonRepeatingChar(string s)
{
	map<char,int> m;
	map<char,int>:: iterator it;
	for(int i=0;i<s.length();i++)
	{
		it=m.find(s[i]);
		if(it==m.end())
			m.insert(pair<char,int>(s[i],1));
		else
			it->second+=1;
	}
	for(int i=0;i<s.length();i++)
	{
		it=m.find(s[i]);
		if(it->second==1)
		{
			cout<<it->first<<endl;
			break;
		}	
	}
	
	return;
}

int main()
{
	string s;
	getline(cin,s,'\n');
	firstNonRepeatingChar(s);
	return 0;
}