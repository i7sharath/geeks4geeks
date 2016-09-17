#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left,*right;
};

TreeNode *createNewNode(int data)
{
	if(data==-1)
		return NULL;
	TreeNode *newNode=(TreeNode*)malloc(sizeof(TreeNode));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

TreeNode *createTree(TreeNode *root,vector<int> &vec)
{
	int n=vec.size();
	if(n==0)
		return NULL;

	queue<TreeNode*> q;
	root=createNewNode(vec[0]);
	q.push(root);
	int i=1;
	while(i<n && !q.empty())
	{
		TreeNode *temp=q.front();
		q.pop();
	
		temp->left=createNewNode(vec[i]);
		if(temp->left)
			q.push(temp->left);
		i++;
		
		if(i>=n)
			break;
		temp->right=createNewNode(vec[i]);
		i++;
		if(temp->right)
			q.push(temp->right);

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

void printLeftNodes(TreeNode *root)
{
	if(root==NULL)
		return;
	while(root)
	{
		if(root->left)
		{
			cout<<root->data<<" ";
			root=root->left;
		}
		else if(root->right)
		{
			cout<<root->data<<" ";
			root=root->right;
		}
		else
			break;
	}
	return;
}

void printRightNodes(TreeNode *root)
{
	if(root==NULL)
		return;
	if(root)
	{
		if(root->right)
		{
			printRightNodes(root->right);
			cout<<root->data<<" ";
		}
		else if(root->left)
		{	
			printRightNodes(root->left);
			cout<<root->data<<" ";
		}
	}
	return;
}

void printLeafs(TreeNode *root)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->data<<" ";
		return;
	}	
	printLeafs(root->left);
	printLeafs(root->right);
	return;
}

void boundaryTraversal(TreeNode *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	printLeftNodes(root->left);
	printLeafs(root->left);
	printLeafs(root->right);
	printRightNodes(root->right);
	return;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];

	TreeNode *root=NULL;
	root=createTree(root,vec);

	boundaryTraversal(root);
	return 0;
}