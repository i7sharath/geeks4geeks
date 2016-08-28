#include <bits/stdc++.h>

using namespace std;

int factorial(int num)
{
	if(num==0 || num==1)
		return 1;
	else 
		return (num*(factorial(num-1))%1000003)%1000003;
}

int findsmaller(string s,int l,int r)
{
	int num=0;
	for(int i=l;i<=r;i++)
	{
		if(s[i]<s[l-1])
			num++;
	}
	return num;
}

int lexicographicRank(string s)
{
	int n=s.length();
	int ans=0;
	for(int i=0;i<n;i++)
	{
		int smaller=findsmaller(s,i+1,n-1);
		ans=(ans+(smaller*factorial(n-i-1))%1000003)%1000003;
	}
	return ans+1;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		string s;
		cin>>s;
		string temp=s;
		sort(temp.begin(),temp.end());
		int flag=0;
		for(int i=0;i<temp.length()-1;i++)
		{
			if(temp[i]==temp[i+1])
			{
				cout<<"0"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<lexicographicRank(s)<<endl;
		testcases--;
	}
	return 0;
}