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

void FindLCA(TreeNode *root,vector<int>&vec,vector<int> temp,int key)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		temp.push_back(root->data);
		if(root->data==key)
			vec=temp;
		return;
	}
	if(root->data==key)
	{
		temp.push_back(root->data);
		vec=temp;
		return;
	}

	temp.push_back(root->data);
	FindLCA(root->left,vec,temp,key);
	FindLCA(root->right,vec,temp,key);
	return;
}

void LCABtree(TreeNode *root,int key1,int key2)
{
	vector<int> vec1;
	vector<int> vec2;
	vector<int> temp;
	FindLCA(root,vec1,temp,key1);
	FindLCA(root,vec2,temp,key2);
	
	int i=0;
	for(i=0;i<vec1.size() && i<vec2.size();i++)
	{
		if(vec1[i]!=vec2[i])
			break;
	}
	cout<<vec1[i-1]<<endl;
	return;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	int node1,node2;
	cin>>node1>>node2;
	TreeNode *root1=NULL;
	root1=createTree(root1,vec);
	LCABtree(root1,node1,node2);
	return 0;
}