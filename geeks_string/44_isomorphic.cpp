#include <bits/stdc++.h>

using namespace std;

bool isIsomorphic(string s1,string s2)
{
	map<char,int> m;
	map<char,int>::iterator it;
	set<char> s;
	set<char> :: iterator sit;

	for(int i=0;i<s1.length();i++)
	{
		it=m.find(s1[i]);
		if(it==m.end())
		{
			sit=s.find(s2[i]);
			if(sit==s.end())
			{
				m.insert(pair<char,int>(s1[i],1));
				s.insert(s2[i]);
			}
			else
				return false;
		}
		else
		{
			if(s2[i]!=it->second)
				return false;
		}
	}
	return true;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		string s1,s2;
		cin>>s1>>s2;
		bool flag=isIsomorphic(s1,s2);
		if(flag)
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
		testcases--;
	}
	return 0;
}