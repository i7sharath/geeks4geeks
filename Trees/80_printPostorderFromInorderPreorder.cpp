#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left,*right;
};

TreeNode *createNewNode(int data)
{
	TreeNode *newNode=(TreeNode*)malloc(sizeof(TreeNode));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

int searchIndex(vector<int>&inorder,int data)
{
	int i;
	for(i=0;i<inorder.size();i++)
	{
		if(inorder[i]==data)
			return i;
	}
}

void postOrderTraversal(vector<int> &inorder,vector<int>&preorder,int &index,int start,int end)
{
	if(start>end)
		return;
	int ind=searchIndex(inorder,preorder[index]);
	int rootval=preorder[index++];

	postOrderTraversal(inorder,preorder,index,start,ind-1);
	postOrderTraversal(inorder,preorder,index,ind+1,end);
	cout<<rootval<<" ";
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
	int index=0;
	postOrderTraversal(inorder,preorder,index,0,inorder.size()-1);
	cout<<endl;
	return 0;
}