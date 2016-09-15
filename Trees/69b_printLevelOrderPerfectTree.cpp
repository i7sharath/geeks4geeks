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

void printLevelOrder(TreeNode *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	queue<TreeNode*> q;
	if(root->left && root->right)
	{
		q.push(root->left);
		q.push(root->right);
	}

	while(!q.empty())
	{
		TreeNode *temp1=q.front();
		q.pop();
		TreeNode *temp2=q.front();
		q.pop();
		cout<<temp1->data<<" "<<temp2->data<<" ";
		if(temp1 && temp2)
		{
			if(temp1->left)
				q.push(temp1->left);
			if(temp2->right)
				q.push(temp2->right);
			if(temp1->right)
				q.push(temp1->right);
			if(temp2->left)
				q.push(temp2->left);
		}
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
	printLevelOrder(root);
	cout<<endl;
	return 0;
}
