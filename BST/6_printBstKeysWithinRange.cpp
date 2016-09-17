#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left,*right;
};

void inorder(TreeNode *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

TreeNode *insertNode(TreeNode *root,TreeNode *node)
{
	if(root==NULL)
		return node;
	if(node->data < root->data)
		root->left=insertNode(root->left,node);
	else if(node->data > root->data)
		root->right=insertNode(root->right,node);
	return root;
}

TreeNode *createBinarySearchTree(vector<int> & vec,int n)
{
	TreeNode *root=NULL;
	for(int i=0;i<n;i++)
	{
		TreeNode *node=new TreeNode;
		node->data=vec[i];
		node->left=NULL;
		node->right=NULL;
		root=insertNode(root,node);
	}
	return root;
}

void printKeysWithinRange(TreeNode *root,int k1,int k2)
{
	if(root==NULL)
		return;
	if(root->data > k1)
		printKeysWithinRange(root->left,k1,k2);
	if(root->data>=k1 && root->data <=k2)
		cout<<root->data<<" ";
	if(root->data < k2)
		printKeysWithinRange(root->right,k1,k2);
	return;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	int k1,k2;
	cin>>k1>>k2;
	TreeNode *root=createBinarySearchTree(vec,n);	
	printKeysWithinRange(root,k1,k2);
	return 0;
}
