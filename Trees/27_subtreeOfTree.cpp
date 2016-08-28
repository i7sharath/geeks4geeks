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
void preorder(TreeNode *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int isIdentical(TreeNode *root1,TreeNode *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1==NULL || root2==NULL)
		return 0;	
	return (root1->data==root2->data &&  isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right));
}

int isSubtree(TreeNode *root1,TreeNode *root2)
{
	if(root1==NULL)
		return root2==NULL;
	if(isIdentical(root1,root2))
		return true;

	return isSubtree(root1->left,root2) || isSubtree(root1->right,root2);
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
	preorder(root1);
	cout<<endl;

	int m;
	cin>>m;
	vector<int> subvec(m);
	for(int i=0;i<m;i++)
		cin>>subvec[i];
	TreeNode *root2=NULL;
	root2=createTree(root2,subvec);
	preorder(root2);
	cout<<endl;
	
	if(isSubtree(root1,root2))
		cout<<"true"<<endl;
	else
		cout<<"False"<<endl;

	return 0;	
}