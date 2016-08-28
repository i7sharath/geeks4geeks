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

int checkChildrenSumProperty(TreeNode *root)
{
	if(root==NULL)
		return 1;
	if(root->left==NULL && root->right==NULL)
		return 1;
	if(root->left==NULL)
	{
		if(root->data==root->right->data)
			return 1;
		else
			return 0;
	}

	if(root->right==NULL)
	{
		if(root->data ==root->left->data)
			return 1;
		else
			return 0;
	}
	if(root->data!=((root->left->data) +(root->right->data)))
		return 0;
	else
		return checkChildrenSumProperty(root->left) && checkChildrenSumProperty(root->right);

}

int checkSumProperty(TreeNode *root)
{
	int leftval=0,rightval=0;
	if(root==NULL ||(root->left==NULL && root->right==NULL))
		return 1;
	if(root->left)
		leftval=root->left->data;
	if(root->right)
		rightval=root->right->data;
	if(root->data==(leftval+rightval))
		return checkSumProperty(root->left) && checkSumProperty(root->right);
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

	TreeNode *root=NULL;
	root=createTree(root,vec);
	inorder(root);
	cout<<endl;

	int flag=checkChildrenSumProperty(root);
	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"False"<<endl;

	flag=checkSumProperty(root);
	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}