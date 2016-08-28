#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void maxSubarrayOnesFlipZeroIndex(vector<int>& vec,int m)
{
	vector<int> ans;
	vector<int> temp;
	int maxval=INT_MIN;
	int count=0;
	int wl=0,wr=0,n=vec.size();
	while(wr < n)
	{
		if(vec[wr]==1)
			wr++;
		else
		{
			if(count<m)
			{
				temp.push_back(wr);
				wr++;
				count++;
			}
			else
			{
				if((wr-wl)>maxval)
				{
					maxval=wr-wl;
					ans=temp;
				}
				while(wl<wr)
				{
					if(vec[wl]==1)
						wl++;
					else if(vec[wl]==0)
					{
						count--;
						temp.erase(temp.begin());
						wl++;
						break;
					}

				}
			}
		}
	}
	if(wl<wr)
	{
		if(wr-wl >maxval)
		{
			maxval=wr-wl;
			ans=temp;
		}
	}
	cout<<"maximum length:"<<maxval<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return ;
}

int main()
{
	int testcases;
	cin>>testcases;
	for(int t=0;testcases;t++)
	{
		int n;
		cin>>n;
		vector<int> vec(n);
		for(int i=0;i<n;i++)
			cin>>vec[i];
		int m;
		cin>>m;
		maxSubarrayOnesFlipZeroIndex(vec,m);
	}
	return 0;
}