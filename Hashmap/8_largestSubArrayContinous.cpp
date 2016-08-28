#include <bits/stdc++.h>

using namespace std;

int maxlength(vector<int>& vec,int n)
{
	map<int,int> m;
	map<int,int> :: iterator it;
	int maxlen=INT_MIN;
	int maxval=vec[0],minval=vec[0];
	int start=0,end=0;
	int i=0;
	while(i<n)
	{
		it=m.find(vec[i]);
		if(it==m.end())
		{
			m.insert(pair<int,int>(vec[i],i));
			if(vec[i]>maxval)
				maxval=vec[i];
			else if(vec[i]<minval)
				minval=vec[i];
			i++;
			end++;
			if((end-start)==(maxval-minval+1))
				maxlen=max(maxlen,maxval-minval+1);
		}
		else
		{
			if((end-start)==(maxval-minval+1))
				maxlen=max(maxlen,maxval-minval+1);
			start=it->second+1;
			end=it->second+1;
			minval=vec[start];
			maxval=vec[end];
			i=start;
			m.clear();
		}
	}
	if((end-start)==(maxval-minval+1))
		maxlen=max(maxlen,maxval-minval+1);
	return maxlen;
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;t<testcases;t++)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		cout<<maxlength(vec,n)<<endl;
	}
	return 0;
}