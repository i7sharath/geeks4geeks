#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
};

TreeNode *newNode(int data)
{
	if(data==-1)
		return NULL;
	TreeNode *node=new TreeNode;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

TreeNode *createTree(vector<int> &vec,int n)
{
	if(n==0)
		return NULL;
	
	TreeNode *root=newNode(vec[0]);
	queue<TreeNode*> q;
	q.push(root);
	int i=1;
	while(i<n && !q.empty())
	{
		TreeNode *temp=q.front();
		q.pop();
		temp->left=newNode(vec[i]);

		if(temp->left)
			q.push(temp->left);

		i++;
		if(i>=n)
			break;
		temp->right=newNode(vec[i]);
		
		if(temp->right)
			q.push(temp->right);
		i++;
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

int findMin(TreeNode *root)
{
	if(root==NULL)
		return 0;
	while(root->left)
		root=root->left;
	return root->data;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	
	TreeNode *root=createTree(vec, n);
	
	cout<<findMin(root)<<endl;
	return 0;
}