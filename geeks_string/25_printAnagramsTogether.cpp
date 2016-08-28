#include <bits/stdc++.h>

using namespace std;

void printAnagrams(vector<string>& vec,int n)
{
	map<string,vector<string> > m;
	map<string,vector<string> > :: iterator it;

	for(int i=0;i<n;i++)
	{
		string s=vec[i];
		sort(s.begin(),s.end());
		it=m.find(s);
		if(it==m.end())
		{
			vector<string> temp;
			temp.push_back(vec[i]);
			m.insert(pair<string,vector<string> >(s,temp));
		}
		else
			it->second.push_back(vec[i]);
	}

	for(it=m.begin();it!=m.end();it++)
	{
		vector<string> subvec;
		subvec=it->second;
		for(int i=0;i<subvec.size();i++)
			cout<<subvec[i]<<" ";
		cout<<endl;
	}
	return;
}

int main()
{
	int n;
	cin>>n;
	vector<string> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>vec[i];
	}

	printAnagrams(vec,n);

	return 0;
}