#include <bits/stdc++.h>

using namespace std;

int countSubstring(string s,int n,int k)
{
	int ans=0;
	int distinct_char=0;
	for(int i=0;i<n;i++)
	{
		map<char,int> m;
		distinct_char=0;
		for(int j=i;j<n;j++)
		{
			if(m.find(s[j])==m.end())
				distinct_char++;	
			m[s[j]]++;
			
			if(distinct_char==k)
				ans++;
		}
	}
	return ans;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		string s;
		cin>>s;
		int k;
		cin>>k;
		cout<<countSubstring(s,s.length(),k)<<endl;
		testcases--;
	}
	return 0;
}