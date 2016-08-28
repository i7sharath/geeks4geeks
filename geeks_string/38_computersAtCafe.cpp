#include <bits/stdc++.h>

using namespace std;

int countleaving(string s,int n)
{
	int len=s.length();
	map<char,int> m;
	map<char,int> :: iterator it;
	int count=0;
	for(int i=0;i<len;i++)
	{
		it=m.find(s[i]);
		if(it==m.end())
		{
			if(m.size()==n)
			{
				count++;
				i++;
			}
			else
				m.insert(pair<char,int>(s[i],i));
		}
		else
			m.erase(it);
	}
	return count;
}

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	cout<<countleaving(s,n)<<endl;

	return 0;
}