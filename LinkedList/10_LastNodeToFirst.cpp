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
		cout<<head->data;
		head=head->next;
		if(head)
			cout<<"->";
	}
	cout<<endl;
	return;
}

struct node *lastNodeTofront(node* head)
{
	if(head==NULL || head->next==NULL)
		return head;

	node *curr=head;
	while(curr->next)
		curr=curr->next;
	curr->next=head;

	curr=head;
	while(curr->next->next!=head)
		curr=curr->next;
	
	head=curr->next;
	curr->next=NULL;
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
	
	printList(head);
	head=lastNodeTofront(head);
	printList(head);
	
	return 0;
}