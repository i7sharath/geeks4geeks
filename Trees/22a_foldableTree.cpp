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

void mirror(TreeNode *root)
{
	if(root==NULL || (root->left==NULL && root->right==NULL))
		return ;
	mirror(root->left);
	mirror(root->right);
	swap(root->left,root->right);
	return ;
}

int isStructSame(TreeNode *root1,TreeNode *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL))
		return 0;
	else
		return isStructSame(root1->left,root2->left) && isStructSame(root1->right,root2->right);
}

int checkFoldable(TreeNode *root)
{
	if(root==NULL)
		return 1;
	mirror(root->left);
	int res=isStructSame(root->left,root->right);
	mirror(root->left);
	return res;
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
	inorder(root);
	cout<<endl;

	int flag=checkFoldable(root);
	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"False"<<endl;

	return 0;
}