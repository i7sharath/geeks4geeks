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

int findmax(vector<int> &inorder,int start,int end)
{
	int index;
	int maxval=INT_MIN;
	for(int i=start;i<=end;i++)
	{	
		if(inorder[i] > maxval)
		{
			index=i;
			maxval=inorder[i];
		}
	}
	return index;
}


TreeNode *constructTree(vector<int> &inorder,int start,int end)
{
	if(start>end)
		return NULL;
	int index=findmax(inorder,start,end);
	TreeNode *root=createNewNode(inorder[index]);
	if(start==end)
		return root;
	root->left=constructTree(inorder,start,index-1);
	root->right=constructTree(inorder,index+1,end);
	return root;
}


int main()
{
	int n;
	cin>>n;
	vector<int> inorder(n);
	for(int i=0;i<n;i++)
		cin>>inorder[i];
	TreeNode *root=NULL;
	root=constructTree(inorder,0,inorder.size()-1);
	inordertraversal(root);
	cout<<endl;
	return 0;
}