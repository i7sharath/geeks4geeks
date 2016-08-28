#include <bits/stdc++.h>

using namespace std;

string Helper(string s1,string s2)
{
	int len1=s1.length(),len2=s2.length();
	int i=0,j=0;
	string ans;
	while(i<len1 && j<len2)
	{
		if(s1[i]!=s2[j])
			break;
		ans+=s1[i];
		i++;
		j++;
	}
	return ans;
}

string longestCommonPrefix(vector<string>& vec,int start,int end)
{
	if(start==end)
		return vec[start];
	int  mid=start+(end-start)/2;
	string s1=longestCommonPrefix(vec,start,mid);
	string s2=longestCommonPrefix(vec,mid+1,end);
	return Helper(s1,s2);
}

int main()
{
	int n;
	cin>>n;
	vector<string> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	cout<<longestCommonPrefix(vec,0,n-1)<<endl;
	return 0;
}
