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

void preorder(TreeNode *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	return;
}

TreeNode *deepestLeftLeaf(TreeNode *root)
{
	if(root==NULL)
		return root;
	queue<TreeNode *> q;
	q.push(root);
	q.push(NULL);
	TreeNode *pre=root;
	while(!q.empty())
	{
		TreeNode *temp=q.front();
		q.pop();
		if(temp)
		{
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		else
		{
			if(!q.empty())
			{	
				pre=q.front();
				q.push(NULL);
			}
			else
				return pre;
		}
	}
	return pre;	
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
	root=deepestLeftLeaf(root);
	if(root)
		cout<<root->data<<endl;
	else
		cout<<"NULL"<<endl;
	return 0;
}
