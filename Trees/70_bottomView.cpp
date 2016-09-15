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

void bottomView(TreeNode *root)
{
	if(root==NULL)
		return;
	map<int,TreeNode*> m;
	map<int,TreeNode*> ::iterator it;
	queue<pair<TreeNode*,int> > q;
	q.push(make_pair(root,0));

	while(!q.empty())
	{
		pair<TreeNode*,int> temp=q.front();
		q.pop();
		TreeNode *node=temp.first;
		int index=temp.second;
		it=m.find(index);
		if(it==m.end())
			m.insert(pair<int,TreeNode*>(index,node));
		else
			m[index]=node;
		if(node)
		{
			if(node->left)
				q.push(make_pair(node->left,index-1));
			if(node->right)
				q.push(make_pair(node->right,index+1));
		}
	}

	for(it=m.begin();it!=m.end();it++)
		cout<<it->second->data<<" ";
	cout<<endl;
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
	bottomView(root);
	return 0;
}
