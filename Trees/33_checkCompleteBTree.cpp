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

bool checkCompleteBTree(TreeNode *root)
{
	if(root==NULL)
		return true;
	queue<TreeNode *> q;
	q.push(root);
	bool flag=false;
	while(!q.empty())
	{
		TreeNode *temp=q.front();
		q.pop();
		if(temp->left)
		{
			if(flag==true)
				return false;
			q.push(temp->left);
		}
		else
			flag=true;

		if(temp->right)
		{
			if(flag==true)
				return false;
			q.push(temp->right);
		}
		else
			flag=true;
	}
	return true;
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

	int flag=checkCompleteBTree(root);
	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"False"<<endl;

	return 0;
}