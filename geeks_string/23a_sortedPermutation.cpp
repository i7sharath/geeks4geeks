#include <bits/stdc++.h>

using namespace std;

int findIndex(string s,int l,int r)
{
	int ind=l;
	for(int i=l+1;i<=r;i++)
	{
		if(s[i]>s[l-1] && s[i]<s[ind])
			ind=i;
	}
	return ind;
}

void Nextpermutation(string s)
{
	bool finished=false;
	int first,second;
	while(finished!=true)
	{
		cout<<s<<endl;
		int i;
		for( i=s.length()-2;i>=0;i--)
		{
			if(s[i]<s[i+1])
			{
				first=i;
				break;
			}
		}

		if(i==-1)
			finished=true;

		int second=findIndex(s,first+1,s.length()-1);
		swap(s[first],s[second]);
		//sort(s.begin()+first+1,s.end());
		reverse(s.begin()+first+1,s.end());		
	}
}


int main()
{
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	Nextpermutation(s);
	return 0;
}