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

void MorrisInordertraversal(TreeNode *root)
{
	if(root==NULL)
		return;
	TreeNode *pre;
	while(root)
	{
		if(root->left==NULL)
		{
			cout<<root->data<<" ";
			root=root->right;
		}
		else
		{
			pre=root->left;
			while(pre->right && pre->right!=root)
				pre=pre->right;

			if(pre->right==NULL)
			{
				pre->right=root;
				root=root->left;
			}
			else
			{
				pre->right=NULL;
				cout<<root->data<<" ";
				root=root->right;
			}
		}
	}
	cout<<endl;
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
	MorrisInordertraversal(root);
	return 0;
}