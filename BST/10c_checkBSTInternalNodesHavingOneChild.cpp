#include <bits/stdc++.h>

using namespace std;

int checkBSTInternalNodesOneChild(vector<int>&preorder,int n)
{
	int minval=min(preorder[n-1],preorder[n-2]);
	int maxval=max(preorder[n-1],preorder[n-2]);

	for(int i=n-3;i>=0;i--)
	{
		if(preorder[i] <minval)
			minval=preorder[i];
		else if(preorder[i]>maxval)
			maxval=preorder[i];
		else
			return 0;
	}
	return 1;
}

int main()
{
	int n;
	cin>>n;
	vector<int> preorder(n);
	for(int i=0;i<n;i++)
		cin>>preorder[i];
	int flag=checkBSTInternalNodesOneChild(preorder,n);
	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}
