#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;

void removesDuplicates(string s)
{
	map<char,int> m;
	map<char,int>::iterator it;
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
	char ch;
	int index=0;
	int size=s.length();
	for(int i=0;i<size;i++)
	{
		it=m.find(s[i]);
		if(it->second>=1)
		{
			s[index]=it->first;
			it->second=0;
			index++;
		}
	}
	s.resize(index);
	cout<<s<<endl;
	return;
}

int main()
 {
	
	string s;
	getline(cin,s,'\n');
	removesDuplicates(s);
	return 0;
}