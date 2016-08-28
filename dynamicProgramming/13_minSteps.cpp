#include <bits/stdc++.h>

using namespace std;

int n;
int minSteps(vector<int> steps,int start,int end)
{
	int stepscount=0;
	if(start>end)
		return stepscount;
	if(start==n-1)
		return stepscount;
 
	stepscount=stepscount+1;
	int index=start+steps[start];
	for(int i=start;i<=index;i++)
	{
		if(i<end)
		{
			int count=minSteps(steps,i,end);
			if(count>stepscount)
				stepscount=count;
		}
		
	}
	return stepscount;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		cin>>n;
		vector<int> steps(n);
		for(int i=0;i<n;i++)
			cin>>steps[i];
		cout<<minSteps(steps,0,n-1)<<endl;
		testcases--;
	}
	return 0;
}