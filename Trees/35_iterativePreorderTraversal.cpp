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

void preordertraversal(TreeNode *root)
{
	if(root==NULL)
		return ;
	stack<TreeNode*> st;
	while(1)
	{
		while(root)
		{
			cout<<root->data<<" ";
			st.push(root);
			root=root->left;
		}
		if(st.empty())
			break;
		TreeNode *temp=st.top();
		st.pop();
		root=temp->right;
	}
	cout<<endl;
	return;
}

void preorder(TreeNode *root)
{
	if(root==NULL)
		return;
	stack<TreeNode*> st;
	st.push(root);
	while(!st.empty())
	{
		TreeNode *temp=st.top();
		st.pop();
		cout<<temp->data<<" ";
		if(temp->right)
			st.push(temp->right);
		if(temp->left)
			st.push(temp->left);
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
	preordertraversal(root);
	preorder(root);
	return 0;
}