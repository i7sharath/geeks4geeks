#include <bits/stdc++.h>

using namespace std;

void removeElements(string s,int n)
{
	int  index=0;
	int i=0;
	while(i<n)
	{
		if(s[i]=='b')
			i++;
		else if(i<n-1 && s[i]=='a' && s[i+1]=='c')
			i=i+2;
		else 
		{
			s[index++]=s[i];
			i++;
		}
	}
	s.erase(s.begin()+index,s.end());
	cout<<s<<endl;
	return ;
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
		removeElements(s,n);
		testcases--;
	}
	return 0;
}