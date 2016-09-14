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

void ModifyTree(TreeNode* root,vector<int>&q,int index,int &vecindex)
{
	if(root==NULL)
		return;
	ModifyTree(root->left,q,index+1,vecindex);
	if(index & 1)
		root->data=q[vecindex++];
	ModifyTree(root->right,q,index+1,vecindex);
	return;
}

void reverseAlternateLevels(TreeNode *root,vector<int> &q,int index)
{
	if(root==NULL)
		return;

	reverseAlternateLevels(root->left,q,index+1);
	if(index & 1)
		q.push_back(root->data);
	
	reverseAlternateLevels(root->right,q,index+1);
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

	vector<int> q;
	reverseAlternateLevels(root,q,0);
	reverse(q.begin(),q.end());
	int index=0,vecindex=0;
	ModifyTree(root,q,index,vecindex);
	preorder(root);
	cout<<endl;
	return 0;
}
