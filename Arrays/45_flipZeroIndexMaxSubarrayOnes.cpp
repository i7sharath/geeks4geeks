#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSubarrayOnesFlipZeroIndex(vector<int>& vec)
{
	int index=0,maxval=INT_MIN;
	int count=0,currindex=-1;
	int wl=0,wr=0,n=vec.size();
	while(wr < n)
	{
		if(vec[wr]==1)
			wr++;
		else
		{
			if(count==0)
			{
				currindex=wr;
				wr++;
				count=1;
			}
			else
			{
				if((wr-wl)>maxval)
				{
					maxval=wr-wl;
					index=currindex;
				}
				while(wl<wr)
				{
					if(vec[wl]==1)
						wl++;
					else if(vec[wl]==0)
					{
						count--;
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
			index=currindex;
		}
	}
	cout<<"maximum length:"<<maxval<<endl;
	return index;
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
		cout<<"flipped index:"<<maxSubarrayOnesFlipZeroIndex(vec)<<endl;
	}
	return 0;
}