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

int IsSiblings(TreeNode *root,int a,int b)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 0;
	if((root->left->data==a && root->right->data==b) || (root->left->data==b && root->right->data==a))
		return 1;
	
	return IsSiblings(root->left,a,b) || IsSiblings(root->right,a,b);
}

int findLevel(TreeNode *root,int a,int index)
{
	if(root==NULL)
		return 0;
	if(root->data==a)
		return index;
	int lindex=findLevel(root->left,a,index+1);
	if(lindex!=0)
		return lindex;
	return findLevel(root->right,a,index+1);
}

int IsCousins(TreeNode *root,int a,int b)
{
	if((findLevel(root,a,1)==findLevel(root,b,1)) && !IsSiblings(root,a,b))
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	int a,b;
	cin>>a>>b;
	TreeNode *root=NULL;
	root=createTree(root,vec);
	cout<<IsCousins(root,a,b)<<endl;
	return 0;
}
