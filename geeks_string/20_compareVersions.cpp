#include <bits/stdc++.h>

using namespace std;

int compareVersions(string s1,string s2)
{
	long long int n1=s1.length();
	long long int n2=s2.length(),i=0,j=0;
	long double val1=0,val2=0;
	while(i<n1 || j<n2)
	{
		val1=0;
		val2=0;
		while(i<n1 && s1[i]!='.')
		{
			val1=val1*10+s1[i]-'0';
			i++;
		}

		while(j<n2 && s2[j]!='.')
		{
			val2=val2*10+s2[j]-'0';
			j++;
		}
		if(val1>val2)
			return 1;
		else if(val1<val2)
			return -1;
		else
		{
			i++;
			j++;
		}
	}
	return 0;
}


int main()
{
	string s1,s2;
	cin>>s1;
	cin>>s2;
	cout<<compareVersions(s1,s2)<<endl;
	return 0;
}