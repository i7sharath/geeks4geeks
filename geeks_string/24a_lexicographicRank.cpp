#include <bits/stdc++.h>

using namespace std;

int findIndex(string temp,int l,int r)
{
	int ind=l;
	for(int i=l+1;i<=r;i++)
	{
		if(temp[i]>temp[l-1] && temp[i]<temp[ind])
			ind=i;
	}
	return ind;
}

void Nextpermutation(string s,string temp)
{
	int first,second;
	int rank=0;
	while(1)
	{
		rank=(rank+1)%1000003;
		if(s==temp)
		{
			cout<<rank<<endl;
			return;
		}
		int i;
		for( i=temp.length()-2;i>=0;i--)
		{
			if(temp[i]<temp[i+1])
			{
				first=i;
				break;
			}
		}

		if(i==-1)
			break;

		int second=findIndex(temp,first+1,s.length()-1);
		swap(temp[first],temp[second]);
		reverse(temp.begin()+first+1,temp.end());		
	}
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
		for(int i=0;i<temp.length()-1;i++)
		{
			if(temp[i]==temp[i+1])
			{
				cout<<"0"<<endl;
				return 0;
			}
		}
		Nextpermutation(s,temp);

		testcases--;
	}
	return 0;
}