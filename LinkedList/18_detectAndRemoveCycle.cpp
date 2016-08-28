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

node *detectRemoveCycle(node *head)
{
	if(head==NULL)
		return head;
	if(head->next==head)
	{
		head->next=NULL;
		return head;
	}

	node *slow=head,*fast=head;
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			break;
	}

	slow=head;
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}

	fast->next=NULL;
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
	head=detectRemoveCycle(head);
	printList(head);
	return 0;
}