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


TreeNode *constructTree(vector<int>&inorder,vector<int> &postorder,int &index,int start,int end)
{
	if(start>end)
		return NULL;
	TreeNode *root=createNewNode(postorder[index--]);
	if(start==end)
		return root;

	int ind=searchIndex(inorder,start,end,root->data);
	root->right=constructTree(inorder,postorder,index,ind+1,end);
	root->left=constructTree(inorder,postorder,index,start,ind-1);
	return root;
}

int main()
{
	int n;
	cin>>n;
	vector<int> inorder(n);
	for(int i=0;i<n;i++)
		cin>>inorder[i];
	vector<int> postorder(n);
	for(int i=0;i<n;i++)
		cin>>postorder[i];
	TreeNode *root=NULL;

	int index=n-1;
	root=constructTree(inorder,postorder,index,0,n-1);
	inordertraversal(root);
	cout<<endl;
	return 0;
}