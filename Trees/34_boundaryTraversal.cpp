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

void rightView(TreeNode *root,vector<int> & rightvec,int index)
{
	if(root)
	{
		if(index+1> rightvec.size())
			rightvec.push_back(root->data);
		rightView(root->right,rightvec,index+1);
		rightView(root->left,rightvec,index+1);
	}
	return;
}

void leftView(TreeNode *root,vector<int> & leftvec,int index)
{
	if(root)
	{
		if(index+1 > leftvec.size())
			leftvec.push_back(root->data);
		leftView(root->left,leftvec,index+1);
		leftView(root->right,leftvec,index+1);
	}
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
	inorder(root);
	cout<<endl;

	if(root==NULL)
		return 0;

	vector<int> leftvec;
	vector<int> rightvec;

	int index=0;
	rightView(root,rightvec,index);
	index=0;
	leftView(root,leftvec,index);

	for(int i=rightvec.size()-1;i>0;i--)
		leftvec.push_back(rightvec[i]);

	for(int i=0;i<leftvec.size();i++)
		cout<<leftvec[i]<<" ";
	cout<<endl;

	return 0;
}