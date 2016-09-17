#include <bits/stdc++.h>

using namespace std;

int checkBSTInternalNodesOneChild(vector<int>&vec,int n)
{
	if(n==0)
		return 1;
	int flag=1;
	for(int i=0;i<n-1;i++)
	{
		if((vec[i] > vec[i+1]) && (vec[i] > vec[n-1] ) || (vec[i] < vec[i+1] && vec[i] < vec[n-1]) )
			flag=1;
		else
		{
			flag=0;
			break;
		}
	}

	return flag;
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