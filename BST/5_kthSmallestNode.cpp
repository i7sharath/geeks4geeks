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
	cout<<root->data<<":"<<root->lcount<<" "	;
	inorder(root->right);
	return;
}

TreeNode *insertNode(TreeNode *root,TreeNode *node)
{
	if(root==NULL)
		return node;
	if(node->data < root->data)
	{
		root->lcount++;
		root->left=insertNode(root->left,node);
	}
	else if(node->data > root->data)
	{
		root->right=insertNode(root->right,node);
	}
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
		node->lcount=0;
		root=insertNode(root,node);
	}
	return root;
}

TreeNode *KthSmallestNode(TreeNode  *root,int k)
{
	if(root==NULL)
		return root;
	if(root->lcount+1 == k)
		return root;
	if(root->lcount+1 < k)
	{
		k=k-(root->lcount+1);
		return KthSmallestNode(root->right,k);
	}
	else
		return KthSmallestNode(root->left,k);
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	int k;
	cin>>k;
	TreeNode *root=createBinarySearchTree(vec,n);
	inorder(root);
	cout<<endl;
	TreeNode *kthNode=KthSmallestNode(root,k);
	cout<<kthNode->data<<endl;
	return 0;
}
