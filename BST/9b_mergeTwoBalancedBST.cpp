#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left,*right;	
};

void inordertraversal(TreeNode *root)
{
	if(root==NULL)
		return;
	inordertraversal(root->left);
	cout<<root->data<<" ";
	inordertraversal(root->right);
	return;
}


TreeNode *insertNode(TreeNode *root,TreeNode *node)
{
	if(root==NULL)
		return node;
	if(node->data < root->data)
		root->left=insertNode(root->left,node);
	else if(node->data > root->data)
		root->right=insertNode(root->right,node);
	return root;
}

TreeNode *newNode(int data)
{
	TreeNode *node=new TreeNode;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

TreeNode *createBinarySearchTree(vector<int> & vec,int n)
{
	TreeNode *root=NULL;
	for(int i=0;i<n;i++)
	{
		TreeNode *node=newNode(vec[i]);
		root=insertNode(root,node);
	}
	return root;
}

void populateinorder(TreeNode *root,vector<int>&vec)
{
	if(root==NULL)
		return ;
	populateinorder(root->left,vec);
	vec.push_back(root->data);
	populateinorder(root->right,vec);
	return;
}

vector<int> mergeArrays(vector<int>&vec1,vector<int>&vec2,int m ,int n)
{
	vector<int> vec3;
	int i=0,j=0;
	while(i<m && j<n)
	{
		if(vec1[i] <= vec2[j])
			vec3.push_back(vec1[i++]);
		else
			vec3.push_back(vec2[j++]);
	}

	while(i<vec1.size())
		vec3.push_back(vec1[i++]);

	while(j<vec2.size())
		vec3.push_back(vec2[j++]);
	return vec3;
}

TreeNode *MergeBalancedBST(vector<int> &vec,int start,int end)
{
	if(start>end)
		return NULL;
	int mid=start+(end-start)/2;
	TreeNode *root=newNode(vec[mid]);
	if(start==end)
		return root;
	root->left=MergeBalancedBST(vec,start,mid-1);
	root->right=MergeBalancedBST(vec,mid+1,end);
	return root;
}

void mergeTwoBalancedBST(TreeNode *root1,TreeNode *root2,int m,int n)
{
	vector<int> vec1;
	vector<int> vec2;

	populateinorder(root1,vec1);
	populateinorder(root2,vec2);

	vector<int> vec3=mergeArrays(vec1,vec2,m,n);
	
	TreeNode *root=MergeBalancedBST(vec3,0,m+n-1);
	inordertraversal(root);
	cout<<endl;
}

int main()
{
	int m,n;
	cin>>m;
	vector<int> vec1(m);
	for(int i=0;i<m;i++)
		cin>>vec1[i];
	TreeNode *root1=createBinarySearchTree(vec1,m);

	cin>>n;
	vector<int> vec2(n);
	for(int i=0;i<n;i++)
		cin>>vec2[i];
	TreeNode *root2=createBinarySearchTree(vec2,n);

	mergeTwoBalancedBST(root1,root2,m,n);
	return 0;
}