#include <bits/stdc++.h>

using namespace std;

int match(string s1,string s2,int index1,int index2,int n1,int n2)
{
	if(index1==n1 && index2==n2)
		return 1;

	else if(index1<n1 && s1[index1]=='*' && (index1+1)!=n1 && index2==n2)
		return 0;

	else if( (s1[index1]=='?') || (s1[index1]==s2[index2]))
		return match(s1,s2,index1+1,index2+1,n1,n2);

	else if(s1[index1]=='*')
		return match(s1,s2,index1+1,index2,n1,n2) || match(s1,s2,index1,index2+1,n1,n2);
	return 0;
}


int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	int n1=s1.length();
	int n2=s2.length();
	int flag=match(s1,s2,0,0,n1,n2);
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}