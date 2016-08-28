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
void updateSum(TreeNode* &root,int diff)
{
	if(root==NULL)
		return;
	root->data+=diff;
	if(root->left)
		updateSum(root->left,diff);
	else
		updateSum(root->right,diff);
	return;
}
void childrenSumProperty(TreeNode* &root)
{
	if(root==NULL)
		return ;
	int leftval=0,rightval=0;

	if(root->left==NULL && root->right==NULL)
		return ;

	childrenSumProperty(root->left);
	childrenSumProperty(root->right);
	if(root->left)
		leftval=root->left->data;
	if(root->right)
		rightval=root->right->data;

	if(root->data <= (leftval+rightval))
		root->data=(leftval+rightval);
	else
	{
		int diff=(root->data)-(leftval+rightval);
		if(root->left)
			updateSum(root->left,diff);
		else
			updateSum(root->right,diff);
	}
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

	childrenSumProperty(root);
	inorder(root);
	cout<<endl;
	return 0;
}