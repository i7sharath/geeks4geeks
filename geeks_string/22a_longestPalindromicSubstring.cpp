#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s)
{
	int n=s.length();
	vector<vector<int> > cache(n,vector<int>(n,0));
	int maxlen=1;
	//Palindrome of length 1
	for(int i=0;i<n;i++)
		cache[i][i]=1;

	int start=0;
	//Palindrome of length 2
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			cache[i][i+1]=1;
			start=i;
			maxlen=2;
		}
	}

	//Palindrome of length equal to 3 or more
	for(int k=3;k<=n;k++)
	{
		for(int i=0;i<n-k+1;i++)
		{
			int j=i+k-1;
			if(cache[i+1][j-1]!=0 && s[i]==s[j])
			{
				cache[i][j]=1;
				start=i;
				maxlen=max(k,maxlen);
			}
		}
	}

	string ans=s.substr(start,maxlen);
	return ans;

}

int main()
{
	string s;
	getline(cin,s);
	cout<<longestPalindrome(s)<<endl;
	return 0;
}