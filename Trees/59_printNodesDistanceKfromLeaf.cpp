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

void distancefromLeaf(TreeNode *root,vector<int> path,set<int> &s,int k)
{
	if(root==NULL)
		return ;
	if(root->left==NULL && root->right==NULL)
	{
		s.insert(path[path.size()-k]);
		return;
	}
	path.push_back(root->data);
	distancefromLeaf(root->left,path,s,k);
	distancefromLeaf(root->right,path,s,k);
	return;
}


int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	int k;
	cin>>k;
	TreeNode *root=NULL;
	root=createTree(root,vec);
	vector<int> path;
	set<int> s;
	distancefromLeaf(root,path,s,k);

	set<int>::iterator sit;
	for(sit=s.begin();sit!=s.end();sit++)
		cout<<*sit<<" ";
	cout<<endl;
	
	return 0;
}
