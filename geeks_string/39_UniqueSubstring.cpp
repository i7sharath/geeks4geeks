#include <bits/stdc++.h>

using namespace std;

string longestUniqueSubstring(string s,int k,int n)
{
	map<char,int> m;
	map<char,int> :: iterator it;
	string ans;
	
	int i=0,j=0;
	string temp;
	while(i<n)
	{

		it=m.find(s[i]);
		if(it==m.end())
		{
			m.insert(pair<char,int>(s[i],1));
			if(m.size()<=k)
				temp+=s[i];
			else
			{
				if(temp.size()>ans.size())
					ans=temp;
				temp+=s[i];
				while(j<i)
				{
					temp.erase(temp.begin());
					it=m.find(s[j]);
					it->second-=1;
					if(it->second==0)
						m.erase(it);
					if(m.size()<=k)
					{
						if(temp.size()>ans.size())
							ans=temp;
						j++;
						break;
					}
					j++;
				}
			}
		}
		else
		{
			it->second+=1;
			temp+=s[i];
		}
		i++;
	}

	if(temp.size()>ans.size())
		ans=temp;


	m.clear();
	for(int i=0;i<ans.size();i++)
		m[ans[i]]=1;
	if(m.size()<k)
	{
		ans="error";
		return ans;
	}
	return ans;
}

int main()
{
	string s;
	getline(cin,s);
	int k;
	cin>>k;
	cout<<longestUniqueSubstring(s,k,s.length())<<endl;
	return 0;
}