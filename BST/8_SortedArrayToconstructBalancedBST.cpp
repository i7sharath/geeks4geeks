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

TreeNode *newNode(int data)
{
	TreeNode *node=new TreeNode;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

TreeNode *constructBST(vector<int> &vec,int start,int end)
{
	if(start>end)
		return NULL;
	int mid=start+(end-start)/2;
	TreeNode *root=newNode(vec[mid]);
	if(start==end)
		return root;
	root->left=constructBST(vec,start,mid-1);
	root->right=constructBST(vec,mid+1,end);
	return root;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];

	TreeNode *root=constructBST(vec,0,n-1);
	inorder(root);
	cout<<endl;
	return 0;
}