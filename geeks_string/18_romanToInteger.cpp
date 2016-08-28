#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin>>s;
	if(s.length()==0)
		return 0;
	map<char,int> m;
	m['I']=1;
	m['V']=5;
	m['X']=10;
	m['L']=50;
	m['C']=100;
	m['D']=500;
	m['M']=1000;

	int sum=m[s[s.length()-1]];

	for(int i=s.length()-2;i>=0;i--)
	{
		if(m[s[i]]<m[s[i+1]])
			sum-=m[s[i]];
		else
			sum+=m[s[i]];
	}

	cout<<sum<<endl;
	return 0;
}