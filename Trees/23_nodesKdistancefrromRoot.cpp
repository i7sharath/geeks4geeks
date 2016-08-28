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

void nodesAtKthDistance(TreeNode *root,vector<int> &ans,int index,int k)
{
	if(root)
	{
		if(index==k)
			ans.push_back(root->data);
		nodesAtKthDistance(root->left,ans,index+1,k);
		nodesAtKthDistance(root->right,ans,index+1,k);
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

	int k;
	cin>>k;

	TreeNode *root=NULL;
	root=createTree(root,vec);
	inorder(root);
	cout<<endl;

	vector<int> ans;
	nodesAtKthDistance(root,ans,0,k);

	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}