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

bool issubtree(TreeNode *root1,TreeNode *root2)
{
	if(root1==NULL)
		return root2==NULL;

	if(root1->data==root2->data)
	{
		return isidentical
	}
	int lflag=isSubtree(root->left);
	int rflag=issubtree(root->right);
	if(lflag && rfl)
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
	inorder(root1);
	cout<<endl;

	int m;
	vector<int> subvec(m);
	for(int i=0;i<m;i++)
		cin>>subvec[i];
	TreeNode *root2=NULL;
	root2=createTree(root2,subvec);
	inorder(root2);
	cout<<endl;

	bool flag=isSubtree(root);
	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"False"<<endl;

	return 0;
}