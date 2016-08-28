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

int isleaf(TreeNode *root)
{
    if(root==NULL)
        return 0;
    else if(root->left==NULL && root->right==NULL)
        return 1;
    return 0;
}

bool isSumTree(TreeNode* root)
{
    if(root==NULL || isleaf(root))
        return true;
    int lh,rh;
    int flag1=isSumTree(root->left);
    int flag2=isSumTree(root->right);
    if(flag1 && flag2)
    {
        if(root->left==NULL)
            lh=0;
        else if(isleaf(root->left))
            lh=root->left->data;
        else
            lh=2*(root->left->data);
            
        if(root->right==NULL)
            rh=0;
        else if(isleaf(root->right))
            rh=root->right->data;
        else
            rh=2*(root->right->data);
        
        return (root->data==lh+rh);
    }
    return false;
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

	bool flag=isSumTree(root);
	if(flag)
		cout<<"true"<<endl;
	else
		cout<<"False"<<endl;

	return 0;
}