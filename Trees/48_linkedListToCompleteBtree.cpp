#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left,*right;
};

struct node
{
	int data;
	node *next;
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

node *createList(vector<int> & vec)
{
	node *head=NULL,*curr=NULL;
	for(int i=0;i<vec.size();i++)
	{
		if(head==NULL)
		{
			head=(struct node *)malloc(sizeof(node));
			head->data=vec[i];
			curr=head;
		}
		else
		{
			node *temp=(struct node*)malloc(sizeof(node));
			temp->data=vec[i];
			curr->next=temp;
			curr=curr->next;
		}
	}
	return head;
}

void printList(node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
	return;
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

TreeNode *convertLinkedListToBtree(node *head)
{
	if(head==NULL)
		return NULL;

	queue<TreeNode*> q;
	TreeNode *root=createNewNode(head->data);
	q.push(root);
	head=head->next;
	while(head)
	{
		TreeNode *parent=q.front();
		q.pop();
		TreeNode *lchild=NULL,*rchild=NULL;
		lchild=createNewNode(head->data);
		head=head->next;
		q.push(lchild);

		if(head)
		{
			rchild=createNewNode(head->data);
			q.push(rchild);
			head=head->next;
		}
		parent->left=lchild;
		parent->right=rchild;
	}
	return root;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	node *head=NULL;
	head=createList(vec);
	//printList(head);
	TreeNode *root=convertLinkedListToBtree(head);
	preorder(root);
	cout<<endl;
	return 0;
}