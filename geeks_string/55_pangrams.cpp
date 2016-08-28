#include <bits/stdc++.h>

using namespace std;

int checkPangrams(string s,int n)
{
	vector<int> h(26,0);
	for(int i=0;i<n;i++)
	{
		if(isalpha(s[i]))
			h[tolower(s[i])-'a']++;
	}
	
	for(int i=0;i<26;i++)
	{
		if(h[i]==0)
			return 0;
	}
	return 1;

}

int main()
{
	int testcases;
	cin>>testcases;
	getchar();
	while(testcases)
	{
		string s;
		getline(cin,s);
		getchar();
		cout<<checkPangrams(s,s.size())<<endl;
		getchar();
		testcases--;
	}
	return 0;
}