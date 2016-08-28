#include <bits/stdc++.h>

using namespace std;

struct node
{	
	int data;
	struct node *next;
};
	
void insert(node* &head,int val)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	node *start=head;
	if(start==NULL)
	{
		head=newnode;
		return ;
	}

	while(start->next)
		start=start->next;
	start->next=newnode;

	return ;
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

node *DeleteNnodeAterMnodes(node *head,int m,int n,int totalnodes)
{
	node *curr=head;

	while(curr)
	{
		for(int i=0;i<m && curr;i++)
			curr=curr->next;
		node *prevcurr=curr;
		curr=curr->next;
		for(int i=0;i<n && curr;i++)
		{
			node *temp=curr;
			curr=curr->next;
			prevcurr->next=curr;
			prevcurr=prevcurr->next;
			free(temp);
		}
	}
	return head;
}

int main()
{
	struct node *head=NULL;
	int m,n,total;
	cin>>total;
	cin>>m>>n;
	for(int i=0;i<total;i++)
	{
		int val;
		cin>>val;
		insert(head,val);
	}

	head=DeleteNnodeAterMnodes(head,m,n,total);
	printList(head);
	return 0;
}