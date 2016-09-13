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

void printDoublyList(TreeNode *root)
{
	if(root==NULL)
		return ;
	while(root)
	{
		cout<<root->data<<" ";
		root=root->right;
	}
	return;
}

void convertTreeToDoublyList(TreeNode *root,TreeNode * &pre)
{
	if(root==NULL)
		return ;
	convertTreeToDoublyList(root->left,pre);
	root->left=pre;
	if(pre)
		pre->right=root;
	pre=root;
	convertTreeToDoublyList(root->right,pre);
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
	TreeNode *pre=NULL;
	convertTreeToDoublyList(root,pre);
	while(root && root->left)
		root=root->left;
	printDoublyList(root);
	return 0;
}