#include <bits/stdc++.h>

using namespace std;

void permutation(string s)
{
	sort(s.begin(),s.end());
	do{
		cout<<s<<endl;
	}while(next_permutation(s.begin(),s.end()));
	return;
}

int main()
{
	string s;
	cin>>s;
	permutation(s);
	return 0;
}