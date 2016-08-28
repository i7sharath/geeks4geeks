#include <bits/stdc++.h>

using namespace std;

void PalindromePermutation(string s,vector<string>& ans)
{
	string temp=s;
	sort(temp.begin(),temp.end());
	do
	{
		s=temp;
		reverse(s.begin(),s.end());
		if(s==temp)
			ans.push_back(s);
	}
	while(next_permutation(temp.begin(),temp.end()));
	return;
}

int main()
{
	string s;
	cin>>s;
	vector<string> ans;
	PalindromePermutation(s,ans);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j];
		cout<<" ";
	}
	cout<<endl;
	return 0;
}