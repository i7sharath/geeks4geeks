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

vector<vector<int> > Helper(TreeNode *root,vector<vector<int> > &vec,vector<int> subvec)
{
	if(root==NULL)
		return vec;
	if(root->left==NULL && root->right==NULL)
	{
		subvec.push_back(root->data);
		vec.push_back(subvec);
		return vec;
	}
	subvec.push_back(root->data);
	vec=Helper(root->left,vec,subvec);
	vec=Helper(root->right,vec,subvec);
	return vec;
}

vector<vector<int> > rootToLeafPath(TreeNode *root)
{
	vector<vector<int> > paths;
	if(root==NULL)
		return paths;
	vector<int> subvec;
	return Helper(root,paths,subvec);
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
	vector<vector<int> > paths;
	paths=rootToLeafPath(root);
	for(int i=0;i<paths.size();i++)
	{
		for(int j=0;j<paths[i].size();j++)
			cout<<paths[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}