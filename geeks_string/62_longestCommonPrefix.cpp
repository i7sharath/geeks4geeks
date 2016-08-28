#include <bits/stdc++.h>

using namespace std;

void longestPrefix(vector<string>& vec,int n,string& ans)
{
	ans=vec[0];
	for(int i=1;i<n;i++)
	{
		if(ans.size()==0)
			return;
		int j=0,k=0;
		string temp=vec[i];
		while(j<ans.length() && k<temp.length())
		{
			if(ans[j]==temp[k])
			{
				j++;
				k++;
			}
			else
				break;
		}
		if(j<ans.length())
			ans.erase(ans.begin()+j,ans.end());
		else 
			ans.erase(ans.begin()+k,ans.end());
	}
	return ;
}

int main()
{

	int n;
	cin>>n;
	string ans;
	if(n==0)
		return 0;
	vector<string> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	longestPrefix(vec,n,ans);
	cout<<ans<<endl;
	return 0;
}