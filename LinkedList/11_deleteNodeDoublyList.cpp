#include <bits/stdc++.h>

using namespace std;

struct node
{	
	int data;
	struct node *next;
	struct node *prev;
};
	
void insert(node* &head,int val)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	newnode->prev=NULL;

	node *start=head;
	if(start==NULL)
	{
		head=newnode;
		return ;
	}

	while(start->next)
		start=start->next;
	start->next=newnode;
	newnode->prev=start;

	return ;
}

void printList(node *head)
{
	while(head)
	{
		cout<<head->data;
		head=head->next;
		if(head)
			cout<<"->";
	}
	cout<<endl;
	return;
}

struct node *deleteNode(node *head,int val)
{
	if(head==NULL)
		return head;

	if(head->data==val && head->next==NULL)
	{
		free(head);
		return  NULL;
	}

	if(head->data==val)
	{
		node *temp=head;
		head=temp->next;
		head->prev=NULL;
		free(temp);
		return head;
	}

	node *prev=NULL,*curr=head;

	while(curr && curr->next)
	{
		if(curr->data==val)
		{
			prev->next=curr->next;
			curr->next->prev=prev;
			free(curr);
			return head;
		}
		else
		{
			prev=curr;
		}
		curr=curr->next;
	}

	prev->next=NULL;
	curr->prev=NULL;
	free(curr);

	return head;
}

int main()
{
	struct node *head=NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		insert(head,val);
	}
		
	int val;
	cin>>val;
	printList(head);
	head=deleteNode(head,val);
	printList(head);
	return 0;
}