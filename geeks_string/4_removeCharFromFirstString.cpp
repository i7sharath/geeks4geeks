#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;


void removecharfromfirststring(string s1,string s2)
{
	map<char,int> m;
	map<char,int>:: iterator it;
	for(int i=0;i<s2.length();i++)
	{
		it=m.find(s2[i]);
		if(it==m.end())
		{
			m.insert(pair<char,int>(s2[i],1));
		}
	}
	int index=0;
	for(int i=0;i<s1.length();i++)
	{
		it=m.find(s1[i]);
		if(it==m.end())
		{
			s1[index++]=s1[i];
		}
	}
	s1.resize(index);
	cout<<s1<<endl;
	return;
}

int main()
{
	
	string s1,s2;
	getline(cin,s1,'\n');
	getline(cin,s2,'\n');
	removecharfromfirststring(s1,s2);
	return 0;
}