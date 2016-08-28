#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
	struct TreeNode *random;

};

struct TreeNode *newNode(struct TreeNode *root,int data)
{
	struct TreeNode *node=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	node->random=NULL;
	return node;
}


void preorder(struct TreeNode *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
struct TreeNode *buildTree(struct TreeNode *root,vector<int>& vec,int n)
{
	if(n==0)
		return root;

	queue<TreeNode*> q;
	int index=0;
	
	if(root==NULL)
		root=newNode(root,vec[index++]);

	TreeNode *node;
	q.push(root);
	while(!q.empty() && index<n)
	{
		struct TreeNode *temp=q.front();
		q.pop();
		
		node=newNode(root,vec[index++]);
		temp->left=node;
		q.push(temp->left);	
		
		if(index>=n)
			break;

		node=newNode(root,vec[index++]);
		temp->right=node;
		q.push(temp->right);		
		
	}
	return root;
	
}


struct TreeNode *auxCloneTree(struct TreeNode *root,map<TreeNode*,TreeNode*>& m)
{
	if(root==NULL)
			return root;
	map<TreeNode*,TreeNode*> :: iterator it;
	TreeNode *clonenode=newNode(root,root->data);
	m.insert(pair<TreeNode*,TreeNode*>(root,clonenode));
	clonenode->left=auxCloneTree(root->left,m);
	clonenode->right=auxCloneTree(root->right,m);
	return clonenode;
}

void cloneRandom(TreeNode *root,TreeNode *cloneroot,map<TreeNode*,TreeNode*>& m)
{
	if(root==NULL)
		return ;
	cloneroot->random=m[root];
	cloneRandom(root->left,cloneroot->left,m);
	cloneRandom(root->right,cloneroot->right,m);
	return;
}

struct TreeNode *cloneTree(struct TreeNode *root,struct TreeNode *cloneroot)
{
	if(root==NULL)
		return root;
	map<TreeNode*,TreeNode*> m;
	cloneroot=auxCloneTree(root,m);
	cloneRandom(root,cloneroot,m);
	return cloneroot;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	struct TreeNode *root=NULL;
	root=buildTree(root,vec,n);

	//print the preorder traversal tree
	cout<<"preorder traversal before cloning"<<endl;
	preorder(root);
	cout<<endl;

	//cloning a tree
	struct TreeNode *cloneroot=NULL;
	cloneroot=cloneTree(root,cloneroot);


	//print the preorder traversal tree
	cout<<"preorder traversal after cloning"<<endl;
	preorder(cloneroot);
	cout<<endl;

	

	return 0;
}