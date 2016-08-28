#include <bits/stdc++.h>

using namespace std;

long long int factorial(long long int num)
{
	if(num==0 || num==1)
		return 1;
	else 
		return num*factorial(num-1);
}


int lexicographicRank(string s)
{
	vector<int> count(256,0);
	int n=s.length();
	int rank=0;

	//populate count of chaacters in string
	for(int i=0;i<n;i++)
	{
		count[s[i]]++;
	}

	for(int i=1;i<256;i++)
	{
		count[i]+=count[i-1];
	}
	long long int mult=factorial(n);
	for(int i=0;i<n;i++)
	{
		mult/=(n-i);
		rank=(rank+((count[s[i]-1])*mult)%1000003)%1000003;
		int ch=s[i];
		for(int j=ch;j<256;j++)
		{
			count[j]--;
		}
	}



	return rank+1;
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