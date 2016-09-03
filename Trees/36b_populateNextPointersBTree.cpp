#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left,*right,*next;
};

TreeNode *createNewNode(int data)
{
	if(data==-1)
		return NULL;
	TreeNode *newNode=(TreeNode*)malloc(sizeof(TreeNode));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	newNode->next=NULL;
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

void printNextPointers(TreeNode *root)
{
	if(root==NULL)
		return;
	if(root)
	{
		cout<<root->data<<":";
		if(root->next)
			cout<<root->next->data;
		cout<<endl;
	}
	printNextPointers(root->left);
	printNextPointers(root->right);
	return;
}


TreeNode *Helper(TreeNode *root)
{
	if(root==NULL)
		return root;
	if(root->left)
		root->left->next=root->right;
	if(root->right)
	{
		if(root->next)
			root->right->next=root->next->left;
		else
			root->right->next=NULL;
	}
	Helper(root->left);
	Helper(root->right);
	return root;
}

TreeNode *populateNextPointers(TreeNode *root)
{
	if(root==NULL)
		return root;
	root->next=NULL;
	return Helper(root);
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
	root=populateNextPointers(root);
	printNextPointers(root);
	return 0;
}