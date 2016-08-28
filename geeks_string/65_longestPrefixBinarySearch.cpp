#include <bits/stdc++.h>

using namespace std;

int minimumLength(vector<string>& vec,int n)
{
	if(vec.size()==0)
		return 0;
	int minval=vec[0].length();
	for(int i=1;i<n;i++)
	{
		int val=vec[i].length();
		minval=min(minval,val);
	}
	return minval;
}

bool allContainsPrefix(vector<string>& vec,string s,int start,int end)
{
	for(int i=0;i<vec.size();i++)
	{
		for(int j=start;j<=end;j++)
		{
			if(vec[i][j]!=s[j])
				return false;
		}
	}
	return true;
}

string longestPrefixHelper(vector<string>& vec,string prefix,int start,int end)
{
	if(start>end)
		return prefix;
	int mid=start+(end-start)/2;
	if(allContainsPrefix(vec,vec[0],start,mid))
	{
		prefix=prefix+vec[0].substr(start,mid-start+1);
		prefix=longestPrefixHelper(vec,prefix,mid+1,end);
	}
	else
		prefix=longestPrefixHelper(vec,prefix,start,mid-1);
	return prefix;
}


string longestCommonPrefix(vector<string>& vec,int n)
{
	int len=minimumLength(vec,n);
	string prefix;
	prefix=longestPrefixHelper(vec,prefix,0,len-1);
	return prefix;
}


int main()
{
	int n;
	cin>>n;
	vector<string> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	cout<<longestCommonPrefix(vec,n)<<endl;
	return 0;
}