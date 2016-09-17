#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left,*right;
};

struct ListNode
{
	int data;
	ListNode *next;
};

void inorder(TreeNode *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

void printList(ListNode *head)
{
	if(head==NULL)
		return;
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	return;
}

ListNode *createList(vector<int> &vec,int n)
{
	ListNode *head=NULL,*currhead=NULL;
	if(n==0)
		return head;
	head=(ListNode*)malloc(sizeof(ListNode));
	head->data=vec[0];
	head->next=NULL;
	currhead=head;
	for(int i=1;i<n;i++)
	{
		ListNode *node=(ListNode*)malloc(sizeof(ListNode));
		node->data=vec[i];
		node->next=NULL;
		currhead->next=node;
		currhead=currhead->next;
	}
	return head;
}

TreeNode *newTreeNode(int data)
{
	TreeNode *node=new TreeNode;
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}


TreeNode *constructBalancedBST(ListNode * &head,int n)
{
	if(n<=0)
		return NULL;

	TreeNode *leftsubtree=constructBalancedBST(head,n/2);
	TreeNode *root=newTreeNode(head->data);
	root->left=leftsubtree;
	head=head->next;
	root->right=constructBalancedBST(head,n-n/2-1);
	return root;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	ListNode *head=createList(vec,n);
	// printList(head);
	// cout<<endl;

	TreeNode *root=constructBalancedBST(head,n);
	inorder(root);
	cout<<endl;
	return 0;
}