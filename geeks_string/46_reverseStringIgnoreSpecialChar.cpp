#include <bits/stdc++.h>

using namespace std;

void reverseString(string& s,int n)
{
	int i=0,j=n-1;
	while(i<j)
	{
		while(i<j && (!isalpha(s[i])))
			i++;
		while(i<j &&(! isalpha(s[j])))
			j--;
		if(i<n && j<n)
			swap(s[i],s[j]);
		i++;
		j--;
	}
	return ;
}

int main()
{
	string s;
	cin>>s;
	reverseString(s,s.length());
	cout<<s<<endl;
	return 0;
}