#include <bits/stdc++.h>

using namespace std;

int longestSubseq(string s,int n)
{
	map<char,int> m;
	map<char,int>::iterator it;
	int start=-1;
	int maxlen=INT_MIN;
	int currlen=0;
	for(int i=0;i<n;i++)
	{
		it=m.find(s[i]);
		if(it==m.end())
		{
			m.insert(pair<char,int>(s[i],i));
			currlen=i-start;
		}
		else
		{
			start=max(start,it->second);
			currlen=i-start;
			it->second=i;
		}
		maxlen=max(maxlen,currlen);
	}
	return maxlen;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		string s;
		cin>>s;
		int n=s.length();
		cout<<longestSubseq(s,n)<<endl;
		testcases--;
	}
	return 0;
}