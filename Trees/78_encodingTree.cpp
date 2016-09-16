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

void encodeTree(TreeNode *root,string &ans,vector<int>& data)
{
	if(root==NULL)
	{
		ans+="0";
		return;
	}
	ans+="1";
	data.push_back(root->data);
	encodeTree(root->left,ans,data);
	encodeTree(root->right,ans,data);
	return;
}

TreeNode *decodeTree(string &ans,int &index,vector<int>&data,int &dataindex)
{ 
	if(ans[index]=='0' )
	{
		index++;
		return NULL;
	}
	TreeNode *root=createNewNode(data[dataindex]);
	dataindex++;
	index++;
	root->left=decodeTree(ans,index,data,dataindex);
	root->right=decodeTree(ans,index,data,dataindex);
	return root;
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

	string ans;
	vector<int> data;
	encodeTree(root,ans,data);
	cout<<ans<<endl;

	int index=0,dataindex=0;
	TreeNode *newroot=decodeTree(ans,index,data,dataindex);
	preorder(newroot);
	cout<<endl;
	return 0;
}