#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left,*right;
};

TreeNode *newNode(int data)
{
	if(data==-1)
		return NULL;
	TreeNode *node=new TreeNode;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

TreeNode *createTree(vector<int> &vec,int n)
{
	if(n==0)
		return NULL;
	
	TreeNode *root=newNode(vec[0]);
	queue<TreeNode*> q;
	q.push(root);
	int i=1;
	while(i<n && !q.empty())
	{
		TreeNode *temp=q.front();
		q.pop();
		temp->left=newNode(vec[i]);

		if(temp->left)
			q.push(temp->left);

		i++;
		if(i>=n)
			break;
		temp->right=newNode(vec[i]);
		
		if(temp->right)
			q.push(temp->right);
		i++;
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

int checkValidBST(TreeNode *root,int lowlimit,int highlimit)
{
	if(root==NULL)
		return 1;
	if( (root->data==INT_MIN && root->left) || (root->data==INT_MAX && root->right) )
		return 0;
	if(root->data>=lowlimit && root->data <= highlimit)
		return checkValidBST(root->left,lowlimit,root->data-1) && checkValidBST(root->right,root->data+1,highlimit);
	return 0;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	
	TreeNode *root=createTree(vec, n);
	
	int flag=checkValidBST(root,INT_MIN,INT_MAX);
	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}