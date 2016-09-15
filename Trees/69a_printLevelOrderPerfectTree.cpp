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
	queue<TreeNode*> leftqueue;
	queue<TreeNode*> rightqueue;
	leftqueue.push(root->left);
	rightqueue.push(root->right);
	while(!leftqueue.empty() && !rightqueue.empty())
	{
		TreeNode *temp1=leftqueue.front();
		TreeNode *temp2=rightqueue.front();
		cout<<temp1->data<<" "<<temp2->data<<" ";
		leftqueue.pop();
		rightqueue.pop();
		if(temp1)
		{
			if(temp1->left)
				leftqueue.push(temp1->left);
			if(temp1->right)
				leftqueue.push(temp1->right);
		}
		if(temp2)
		{
			if(temp2->right)
				rightqueue.push(temp2->right);
			if(temp2->left)
				rightqueue.push(temp2->left);
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
