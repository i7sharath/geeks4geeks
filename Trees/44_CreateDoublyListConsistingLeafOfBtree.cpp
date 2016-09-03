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

void printDoublyList(TreeNode *head)
{
	if(head==NULL)
		return;
	while(head)
	{
		cout<<head->data<<" ";
		if(head->left)
			cout<<"left:"<<head->left->data<<" ";
		if(head->right)
			cout<<"right:"<<head->right->data<<" ";
		cout<<endl;
		head=head->right;
	}
	return;
}

void deepestLeftLeaf(TreeNode *root,TreeNode* head,TreeNode* &ans)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		if(ans==NULL)
		{
			head=root;
			head->left=NULL;
			head->right=NULL;
			ans=head;
		}
		else
		{
			head->right=root;
			if(head->right)
				head->right->right=NULL;
			else
				head->right=NULL;
			root->left=head;
			head=head->right;
		}
		return;
	}
	deepestLeftLeaf(root->left,head,ans);
	deepestLeftLeaf(root->right,head,ans);
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
	TreeNode *head=NULL,*ans=NULL;
	deepestLeftLeaf(root,head,ans);
	printDoublyList(ans);
	return 0;
}
