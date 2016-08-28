#include <bits/stdc++.h>

using namespace std;

int countOperation(string s1,string s2)
{
	int n1=s1.length(),n2=s2.length();
	int i=n1-1,j=n2-1;
	int count=0;
	while(i>=0)
	{
		if(s1[i]==s2[j])
		{
			j--;
			i--;
		}
		else
		{
			while(i>=0 && s1[i]!=s2[j])
			{
				count++;
				i--;
			}
			
		}
	}

	return count;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	if(s1.size()!=s2.size())
	{
		cout<<"Not Possible"<<endl;
		return 0;
	}
	string temp1=s1,temp2=s2;
	sort(temp1.begin(),temp1.end());
	sort(temp2.begin(),temp2.end());
	if(temp1!=temp2)
	{
		cout<<"Not Possible"<<endl;
		return 0;
	}

	cout<<countOperation(s1,s2)<<endl;
	return 0;
}