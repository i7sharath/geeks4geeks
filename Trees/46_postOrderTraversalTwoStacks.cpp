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

void postOrderTwostacks(TreeNode *root, stack<TreeNode*>&st1, stack<TreeNode*>&st2)
{
	while(1)
	{
		while(root)
		{
			st1.push(root);
			st2.push(root);
			root=root->right;
		}
		if(st1.empty())
			break;
		TreeNode *temp=st1.top();
		st1.pop();
		root=temp->left;
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
	stack<TreeNode*> st1,st2;
	postOrderTwostacks(root,st1,st2);
	while(!st2.empty())
	{
		cout<<st2.top()->data<<" ";
		st2.pop();
	}
	cout<<endl;
	return 0;
}