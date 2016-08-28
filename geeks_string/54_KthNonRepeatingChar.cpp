#include <bits/stdc++.h>

using namespace std;

char NonRepeatingChar(string s,int k)
{
	map<char,int> m1;
	map<int,char> m2;
	map<char,int> :: iterator it;

	for(int i=0;i<s.length();i++)
	{
		it=m1.find(s[i]);
		if(it==m1.end())
		{
			m1.insert(pair<char,int>(s[i],i));
			m2.insert(pair<int,char>(i,s[i]));
		}
		else
			m2.erase(it->second);
	}

	int count=1;
	map<int,char>:: iterator it2;
	for(it2=m2.begin();it2!=m2.end();it2++)
	{
		
		if(count==k)
			break;
		count++;
	}
	return it2->second;
}

int main()
{
	string s;
	int k;
	cin>>s;
	cin>>k;
	cout<<NonRepeatingChar(s,k)<<endl;
	return 0;
}