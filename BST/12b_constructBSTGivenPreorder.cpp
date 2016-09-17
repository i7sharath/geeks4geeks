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

TreeNode *createNode(int data)
{
	TreeNode *node=new TreeNode;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

TreeNode *constructBST(vector<int> &preorder,int &preindex,int low,int high)
{
	if(preindex>=preorder.size())
		return NULL;
	TreeNode *root=NULL;
	if(preorder[preindex]>=low && preorder[preindex]<=high)
	{
		root=createNode(preorder[preindex]);
		preindex++;
		root->left=constructBST(preorder,preindex,low,root->data-1);
		root->right=constructBST(preorder,preindex,root->data+1,high);
	}
	return root;
}

int main()
{
	int n;
	cin>>n;
	vector<int> preorder(n);
	for(int i=0;i<n;i++)
		cin>>preorder[i];
	int preindex=0;
	TreeNode *root=constructBST(preorder,preindex,INT_MIN,INT_MAX);
	inorder(root);
	cout<<endl;
	return 0;
}