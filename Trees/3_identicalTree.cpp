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

int checkIdentical(TreeNode *root1,TreeNode *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1==NULL && root2!=NULL)
		return 0;
	if(root1!=NULL && root2==NULL)
		return 0;
	if(root1->data!=root2->data)
		return 0;
	else
		return checkIdentical(root1->left,root2->left) && checkIdentical(root1->right,root2->right);
}

int main()
{
	TreeNode *root1=NULL,*root2=NULL;
	int n;
	cin>>n;
	vector<int> vec1(n);
	for(int i=0;i<n;i++)
		cin>>vec1[i];
	root1=createTree(root1,vec1);
	inorder(root1);
	cout<<endl;

	int m;
	cin>>m;
	vector<int> vec2(m);
	for(int i=0;i<m;i++)
		cin>>vec2[i];
	root2=createTree(root2,vec2);
	inorder(root2);
	cout<<endl;
	int flag=checkIdentical(root1,root2);
	if(flag)
		cout<<"Identical trees"<<endl;
	else
		cout<<"Not Identical Trees"<<endl;
	return 0;
}