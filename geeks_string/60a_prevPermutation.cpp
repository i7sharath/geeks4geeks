#include <bits/stdc++.h>

using namespace std;

void prevpermutation(string s)
{
	while(prev_permutation(s.begin(),s.end()))
		cout<<s<<endl;
	return;
}

int main()
{
	string s;
	cin>>s;
	prevpermutation(s);
	return 0;
}