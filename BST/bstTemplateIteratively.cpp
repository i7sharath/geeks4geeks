#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	int lcount;
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
	{
		root=node;
		return root;
	}

	TreeNode *curr=root,*prev=NULL;
	while(curr)
	{
		if(node->data < curr->data)
		{
			prev=curr;
			curr=curr->left;
		}
		else 
		{
			prev=curr;
			curr=curr->right;
		}
	}
	if(node->data > prev->data)
		prev->right=node;
	else
		prev->left=node;
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


int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	TreeNode *root=createBinarySearchTree(vec,n);
	inorder(root);
	return 0;
}
