#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	
	int data;
	struct TreeNode *left;
	struct TreeNode *right;

};

struct TreeNode *newNode(struct TreeNode *root,int data)
{
	struct TreeNode *node=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
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

void preorder(struct TreeNode *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void verticalSum(struct TreeNode *root,map<int,vector<int> >& m,int pos)
{
	if(root==NULL)
		return;
	map<int,vector<int> >::iterator it;
	it=m.find(pos);
	if(it==m.end())
	{
		vector<int> temp;
		temp.push_back(root->data);
		m.insert(pair<int,vector<int> >(pos,temp));
	}
	else
		(it->second).push_back(root->data);
	verticalSum(root->left,m,pos-1);
	verticalSum(root->right,m,pos+1);
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
	// preorder(root);
	// cout<<endl;

	//vertical sum calculated
	map<int,vector<int> > m;
	map<int,vector<int> > :: iterator it;
	int pos=0;
	verticalSum(root,m,pos);
	for(it=m.begin();it!=m.end();it++)
	{
		vector<int> vec;
		vec=it->second;
		// cout<<it->first<<" : ";
		for(int i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
	return 0;
}