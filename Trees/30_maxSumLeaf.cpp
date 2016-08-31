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
void preorder(TreeNode *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void maxsumLeaf(TreeNode *root,int &maxsum,int currsum)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		currsum+=root->data;
		maxsum=max(maxsum,currsum);
		return;
	}
	currsum+=root->data;
	maxsumLeaf(root->left,maxsum,currsum);
	maxsumLeaf(root->right,maxsum,currsum);
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
	preorder(root);
	cout<<endl;
	if(root==NULL)
	{
		cout<<"0"<<endl;
		return 0;
	}
	int maxsum=INT_MIN,currsum=0;
	maxsumLeaf(root,maxsum,currsum);
	cout<<maxsum<<endl;
	return 0;	
}
