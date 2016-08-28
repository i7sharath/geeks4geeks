#include <bits/stdc++.h>

using namespace std;

void longestCommonPrefix(vector<string>& vec,int n,string &ans)
{
	int minlen=vec[0].length();
	for(int i=1;i<n;i++)
	{
		int val=vec[i].size();
		minlen=min(minlen,val);
	}

	for(int i=0;i<minlen;i++)
	{
		int flag=0;
		int j;
		char cur=vec[0][i];
		for(j=1;j<n;j++)
		{
			if(vec[j][i]!=cur)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			ans+=cur;
		else
			break;
	}

	return ;
}

int main()
{
	int n;
	cin>>n;
	if(n==0)
		return 0;
	vector<string> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	string ans;
	longestCommonPrefix(vec,n,ans);
	cout<<ans<<endl;
	return 0;
}