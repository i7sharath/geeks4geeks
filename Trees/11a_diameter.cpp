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

int height(TreeNode *root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
}

int diameterTree(TreeNode *root)
{
	if(root==NULL)
		return 0;

	int leftheight=height(root->left);
	int rightheight=height(root->right);

	int leftdia=diameterTree(root->left);
	int rightdia=diameterTree(root->right);
	int dia=max(leftheight+rightheight+1,max(leftdia,rightdia));
	return dia;
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
	cout<<diameterTree(root)<<endl;
	return 0;
}