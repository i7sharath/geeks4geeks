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

int checkAllLeavesSameLevel(TreeNode *root,int level,int &leaflevel)
{
	if(root==NULL)
		return 1;
	if(root->left==NULL && root->right==NULL)
	{
		if(leaflevel==0)
		{
			leaflevel=level;
			return 1;
		}
		else
			return(level==leaflevel);
	}	
	return checkAllLeavesSameLevel(root->left,level+1,leaflevel) && 
		   checkAllLeavesSameLevel(root->right,level+1,leaflevel);
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
	int level=0,leaflevel=0;
	int flag=checkAllLeavesSameLevel(root,level,leaflevel);
	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}