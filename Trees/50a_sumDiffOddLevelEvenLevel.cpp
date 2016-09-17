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

int getDiffernceEvenOddLevel(TreeNode *root)
{
	int diff=0;
	if(root==NULL)
		return diff;

	queue<TreeNode *> q;
	q.push(root);
	q.push(NULL);
	int odd=1,oddsum=0,evensum=0;
	while(!q.empty())
	{
		TreeNode *temp=q.front();
		q.pop();
		if(temp)
		{
			if(odd)
				oddsum+=temp->data;
			else
				evensum+=temp->data;
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
		else
		{
			if(!q.empty())
				q.push(NULL);
			odd=1-odd;
		}
	}
	diff=oddsum-evensum;
	return diff;
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
	cout<<getDiffernceEvenOddLevel(root)<<endl;
	return 0;
}