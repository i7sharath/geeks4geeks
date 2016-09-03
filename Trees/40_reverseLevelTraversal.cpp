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

void reverseLevelTraversal(TreeNode *root,vector<vector<int> >&ans,int index)
{	
	if(root==NULL)
		return;
	if(index+1> ans.size())
		ans.resize(index+1);
	ans[index].push_back(root->data);
	reverseLevelTraversal(root->left,ans,index+1);
	reverseLevelTraversal(root->right,ans,index+1);
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
	vector<vector<int> > ans;
	reverseLevelTraversal(root,ans,0);
	for(int i=ans.size()-1;i>=0;i--)
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
	cout<<endl;
	return 0;
}