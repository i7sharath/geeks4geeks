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

int checkIsomorphism(TreeNode *root1,TreeNode *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1==NULL || root2==NULL)
		return 0;
	if(root1->data !=root2->data)
		return 0;
	return 
		checkIsomorphism(root1->left,root2->left) && checkIsomorphism(root1->right,root2->right) || checkIsomorphism(root1->left,root2->right) && checkIsomorphism(root1->right,root2->left);
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];

	TreeNode *root1=NULL;
	root1=createTree(root1,vec);
	
	int m;
	cin>>m;
	vector<int> subvec(m);
	for(int i=0;i<m;i++)
		cin>>subvec[i];

	TreeNode *root2=NULL;
	root2=createTree(root2,subvec);
	int flag=checkIsomorphism(root1,root2);
	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"False"<<endl;
	return 0;
}