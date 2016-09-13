#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left,*right;
};

int search(vector<int>&inorder,int data,int start,int end)
{
	for(int i=start;i<=end;i++)
	{
		if(inorder[start]==data)
			return i;
	}
}

void getpostorder(vector<int> &inorder,vector<int> &preorder,vector<int>&postorder,int start,int end)
{
	if(start>end)
		return;
	int ind=search(inorder,preorder[start],start,end);
	//if leftsubtree is not empty,print leftsubtree
	if(ind!=0)
		getpostorder(inorder,preorder,postorder,start,ind-1);

	//if rightsubtree is not empty,print rightsubtree
	if(ind!=inorder.size()-1)
		getpostorder(inorder,preorder,postorder,ind+1,end);

	postorder.push_back(preorder[start]);
	return;
}

int main()
{
	int n;
	cin>>n;
	vector<int> inorder(n);
	for(int i=0;i<n;i++)
		cin>>inorder[i];

	vector<int> preorder(n); 
	for(int i=0;i<n;i++)
		cin>>preorder[i];
	if(inorder.size()==0)
		return 0;
	vector<int> postorder;
	getpostorder(inorder,preorder,postorder,0,inorder.size()-1);
	for(int i=0;i<postorder.size();i++)
		cout<<postorder[i]<<" ";
	cout<<endl;
	return 0;
}