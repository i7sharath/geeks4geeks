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

void LevelOrderTraversal(TreeNode *root,vector<vector<int> > &vec,int index)
{
	if(root==NULL)
		return;

	if(index+1 >vec.size())
		vec.resize(index+1);

	vec[index].push_back(root->data);
	LevelOrderTraversal(root->left,vec,index+1);
	LevelOrderTraversal(root->right,vec,index+1);
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
	inorder(root);
	cout<<endl;

	vector<vector<int> > vec1;
	LevelOrderTraversal(root,vec1,0);
	for(int i=0;i<vec1.size();i++)
	{
		for(int j=0;j<vec1[i].size();j++)
			cout<<vec1[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	return 0;
}