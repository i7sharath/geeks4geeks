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

TreeNode *Helper(TreeNode *root,int key1,int key2,int &d1,int &d2,int &dist,int h)
{
	if(root==NULL)
		return root;
	if(root->data==key1)
	{
		d1=h;
		return root;
	}
	if(root->data==key2)
	{
		d2=h;
		return root;
	}
	TreeNode *llca=Helper(root->left,key1,key2,d1,d2,dist,h+1);
	TreeNode *rlca=Helper(root->right,key1,key2,d1,d2,dist,h+1);

	if(llca && rlca)
	{
		dist=d1+d2-2*h;
		return root;
	}
	else
		return (llca!=NULL)? llca:rlca;
}

int finddistance(TreeNode *root,int key,int h)
{
	if(root==NULL)
		return 0;
	if(root->left==NULL && root->right==NULL && root->data==key)
		return h;
	if(root->data==key)
		return h;

	int lh=finddistance(root->left,key,h+1);
	int rh=finddistance(root->right,key,h+1);

	return (lh!=0)?lh:rh;
}

void distanceBetweenNodes(TreeNode *root,int key1,int key2)
{
	int d1=-1,d2=-1,h=1,dist;
	TreeNode *lca=Helper(root,key1,key2,d1,d2,dist,h);
	if(d1!=-1 && d2!=-1)
	{
		cout<<dist<<endl;
		return;
	}
	//if n1 is a ancestor of n2
	else if(d1!=-1)
	{
		dist=finddistance(lca,key2,0);
		cout<<dist<<endl;
		return;
	}
	///if n2 is a ancestor of n1
	else if(d2!=-1)	
	{
		dist=finddistance(lca,key1,0);
		cout<<dist<<endl;
		return;
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
	int key1,key2;
	cin>>key1>>key2;
	TreeNode *root=NULL;
	root=createTree(root,vec);
	distanceBetweenNodes(root,key1,key2);
	return 0;
}