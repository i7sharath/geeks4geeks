#include <bits/stdc++.h>

using namespace std;

int longestPalindrome1(string s,int len,int n)
{
	for(int i=0;i<n;i++)
	{
		if(s[i]==s[i+n-1])
		{
			string temp=s.substr(i,n);
			string rtemp=temp;
			reverse(rtemp.begin(),rtemp.end());
			if(temp==rtemp)
				return 1;
		}
	}
	return 0;
}



int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		string s;
		cin>>s;
		string str=s+s;
		cout<<longestPalindrome1(str,str.length(),s.length())<<endl;	
		testcases--;
	}
	return 0;
}