#include <bits/stdc++.h>

using namespace std;

bool editDistance(string s1,string s2,int n1,int n2)
{
	int i=0,j=0;
	int flag=0;
	while(i<n1 && j<n2)
	{
		if(s1[i]!=s2[j])
		{
			if(flag==0)
			{
				flag=1;
				if(n1==n2)
				{
					i++;
					j++;
				}
				else if(n1>n2)
					i++;
				else
					j++;
			}
			else
				return false;
		}
		else
		{
			i++;
			j++;
		}
	}
	
	if(flag==0)
	{
		if((n1+1==n2) || (n2+1==n1))
			return true;
		else
			return false;
	}
	else 
	{
		if(i==n1 && j==n2)
			return true;
		else
			return false;
	}
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	bool flag=editDistance(s1,s2,s1.length(),s2.length());
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}