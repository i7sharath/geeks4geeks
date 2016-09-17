#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left,*right;	
};

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

TreeNode *newNode(int data)
{
	TreeNode *node=new TreeNode;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

TreeNode *createBinarySearchTree(vector<int> & vec,int n)
{
	TreeNode *root=NULL;
	for(int i=0;i<n;i++)
	{
		TreeNode *node=newNode(vec[i]);
		root=insertNode(root,node);
	}
	return root;
}

void inorder(TreeNode *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

TreeNode *mergeTwoTrees(TreeNode *root1,vector<int> &vec2,int m,int n)
{
	for(int i=0;i<n;i++)
	{
		TreeNode *node=newNode(vec2[i]);
		root1=insertNode(root1,node);
	}
	return root1;
}

int main()
{
	int m,n;
	cin>>m;
	vector<int> vec1(m);
	for(int i=0;i<m;i++)
		cin>>vec1[i];
	TreeNode *root1=createBinarySearchTree(vec1,m);

	cin>>n;
	vector<int> vec2(n);
	for(int i=0;i<n;i++)
		cin>>vec2[i];
	TreeNode *root2=createBinarySearchTree(vec2,n);

	root1=mergeTwoTrees(root1,vec2,m,n);
	inorder(root1);
	cout<<endl;
	return 0;
}