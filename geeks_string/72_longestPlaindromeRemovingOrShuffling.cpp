#include <bits/stdc++.h>

using namespace std;

string longestPlaindrome(string s,int n)
{
	map<char,int> m;
	map<char,int> :: iterator it;
	string ans,beg,mid,end;

	for(int i=0;i<n;i++)
		m[s[i]]++;

	for(it=m.begin();it!=m.end();it++)
	{
		int freq=it->second;
		if(freq%2==0)
		{
			for(int j=0;j<freq/2;j++)
				beg+=it->first;
		}
		else
		{
			mid=it->first;
			freq--;
			for(int j=0;j<freq/2;j++)
				beg+=it->first;	
		}
	}

	end=beg;
	reverse(end.begin(),end.end());
	ans=beg+mid+end;
	return ans;
}	

int main()
{
	string s;
	cin>>s;
	cout<<longestPlaindrome(s,s.length())<<endl;
	return 0;
}