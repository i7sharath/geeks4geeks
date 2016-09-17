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

int searchNextGreater(vector<int> &vec,int start,int end,int data)
{
	int index=-1;
	for(int i=start+1;i<=end;i++)
	{
		if(vec[i] > data)
			return i;
	}
	return index;
}

TreeNode *constructBST(vector<int> &vec,int start,int end)
{
	if(start>end)
		return NULL;
	TreeNode *root=createNode(vec[start]);
	if(start==end)
		return root;
	
	int index=searchNextGreater(vec,start,end,vec[start]);
	if(index!=-1)
	{
		root->left=constructBST(vec,start+1,index-1);
		root->right=constructBST(vec,index,end);
	}
	else
	{
		root->right=NULL;
		root->left=constructBST(vec,start+1,end);
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
	TreeNode *root=constructBST(vec,0,n-1);
	inorder(root);
	cout<<endl;
	return 0;
}