#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

void permutationwithoutRepeatition(string s,int l,int r,map<string,int> &m)
{
	map<string,int>::iterator it;
	if(l==r)
	{
		it=m.find(s);
		if(it==m.end())
			m.insert(pair<string,int>(s,1));
	}
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s[l],s[i]);
			permutationwithoutRepeatition(s,l+1,r,m);
			swap(s[l],s[i]);
		}
	}
}

int main()
{
	string s;
	map<string,int> m;
	map<string,int>::iterator it;
	getline(cin,s,'\n');
	permutationwithoutRepeatition(s,0,s.size()-1,m);
	for(it=m.begin();it!=m.end();it++)
		cout<<it->first<<endl;
	return 0;
}