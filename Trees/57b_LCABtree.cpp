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

TreeNode *findLCA(TreeNode *root,int key1,int key2)
{
	if(root==NULL)
		return root;
	if(root->data ==key1 || root->data==key2)
		return root;
	TreeNode *llca=findLCA(root->left,key1,key2);
	TreeNode *rlca=findLCA(root->right,key1,key2);
	if(llca && rlca)
		return root;
	else
		return (llca!=NULL)?llca:rlca;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	int key1,key2;
	cin>>key1>>key2;
	TreeNode *root=NULL;
	root=createTree(root,vec);
	TreeNode *ancestor=findLCA(root,key1,key2);
	cout<<ancestor->data<<endl;
	return 0;
}