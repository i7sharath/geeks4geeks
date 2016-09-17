#include <bits/stdc++.h>

using namespace std;

int checkBSTInternalNodesOneChild(vector<int>&preorder,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int diff1=preorder[i]-preorder[i+1];
		int diff2=preorder[i]-preorder[n-1];
		if(diff1*diff2 <0)
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