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

void inordertraversal(TreeNode *root)
{
	if(root==NULL)
		return;
	inordertraversal(root->left);
	cout<<root->data<<" ";
	inordertraversal(root->right);
	return;
}

int searchIndex(vector<int> &inorder,int start,int end,int element)
{
	int i;
	for(i=start;i<=end;i++)
	{
		if(inorder[i]==element)
			return i;
	}
}


TreeNode *constructTree(vector<int>&inorder,vector<int> &preorder,int &index,int start,int end)
{
	if(start>end)
		return NULL;
	TreeNode *root=createNewNode(preorder[index++]);
	if(start==end)
		return root;

	int ind=searchIndex(inorder,start,end,root->data);
	root->left=constructTree(inorder,preorder,index,start,ind-1);
	root->right=constructTree(inorder,preorder,index,ind+1,end);
	return root;
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
	TreeNode *root=NULL;

	int index=0;
	root=constructTree(inorder,preorder,index,0,n-1);
	inordertraversal(root);
	cout<<endl;
	return 0;
}