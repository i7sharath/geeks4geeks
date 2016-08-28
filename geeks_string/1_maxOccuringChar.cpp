#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;

void maxOccuringChar(string str)
{
	map<char,int> m;
	map<char,int>::iterator it;
	for(int i=0;i<str.length();i++)
	{
		it=m.find(str[i]);
		if(it==m.end())
		{
			m.insert(pair<char,int>(str[i],1));
		}
		else
			it->second=it->second+1;
			
	}
	int max=0;
	char ch;
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second >max)
		{
				max=it->second;
				ch=it->first;
		}
	}
	cout<<ch<<endl;
	return;
}

int main()
{
	string str;
	getline(cin,str,'\n');
	maxOccuringChar(str);
	return 0;
}