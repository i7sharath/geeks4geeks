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

TreeNode *findnode(TreeNode *root,int key)
{
	if(root==NULL)
		return NULL;
	if(root->data==key)
		return root;
	TreeNode *l=findnode(root->left,key);
	if(l)
		return l;
	else
		return findnode(root->right,key);
	
}

TreeNode *Helper(TreeNode *root,TreeNode *node)
{
	if(node->right)
	{
		TreeNode *curr=node->right;
		while(curr->left)
			curr=curr->left;
		return curr;
	}

	TreeNode *succ;
	while(root)
	{
		if(node->data < root->data)	
		{
			succ=root;
			root=root->left;
		}
		else if(node->data > root->data)
			root=root->right;
		else 
			return succ;
	}
	return succ;

}

TreeNode *inorderSuceesor(TreeNode *root,int key)
{
	TreeNode *node=findnode(root,key);
	return Helper(root,node);
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	int key;
	cin>>key;
	TreeNode *root=createTree(vec, n);
	TreeNode *succ=inorderSuceesor(root,key);
	cout<<succ->data<<endl;
	return 0;
}