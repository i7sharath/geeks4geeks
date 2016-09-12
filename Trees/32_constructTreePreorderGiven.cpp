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

TreeNode *constructTree(vector<int> &preorder,vector<char> &preorderLN,int &index,int n)
{
	if(index==n)
		return NULL;
	TreeNode *root=createNewNode(preorder[index]);
	if(preorderLN[index]=='L')
	{
		index++;
		return root;
	}
	index++;
	root->left=constructTree(preorder,preorderLN,index,n);
	root->right=constructTree(preorder,preorderLN,index,n);
	return root;
}

int main()
{
	int n;
	cin>>n;
	vector<int> preorder(n);
	for(int i=0;i<n;i++)
		cin>>preorder[i];

	vector<char> preorderLN(n); 
	for(int i=0;i<n;i++)
		cin>>preorderLN[i];

	TreeNode *root=NULL;
	int index=0;
	root=constructTree(preorder,preorderLN,index,n);
	inordertraversal(root);
	cout<<endl;
	return 0;
}