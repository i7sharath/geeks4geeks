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

vector<int> extractLevelOrder(vector<int>&inorder,vector<int>&level,int start,int end)
{
	vector<int> vec;
	for(int i=0;i<level.size();i++)
	{
		for(int j=start;j<=end;j++)
		{
			if(level[i]==inorder[j])
			{
				vec.push_back(level[i]);
				break;
			}
		}
	}
	return vec;
}

TreeNode *constructTree(vector<int>&inorder,vector<int> &levelorder,int &index,int start,int end)
{
	if(start>end)
		return NULL;
	TreeNode *root=createNewNode(levelorder[index++]);
	if(start==end)
		return root;
	int ind=searchIndex(inorder,start,end,root->data);
	vector<int> leftLevel=extractLevelOrder(inorder,levelorder,start,ind-1);
	vector<int> rightLevel=extractLevelOrder(inorder,levelorder,ind+1,end);
	root->left=constructTree(inorder,leftLevel,index,start,ind-1);
	root->right=constructTree(inorder,rightLevel,index,ind+1,end);
	return root;
}

int main()
{
	int n;
	cin>>n;
	vector<int> inorder(n);
	for(int i=0;i<n;i++)
		cin>>inorder[i];
	vector<int> levelorder(n);
	for(int i=0;i<n;i++)
		cin>>levelorder[i];
	TreeNode *root=NULL;

	int index=0;
	root=constructTree(inorder,levelorder,index,0,n-1);
	inordertraversal(root);
	cout<<endl;
	return 0;
}