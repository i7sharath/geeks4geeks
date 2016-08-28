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

void printCircularList(node *head)
{
	if(head==NULL)
		return;

	node *curr=head;
	while(curr->next!=head)
	{
		cout<<curr->data<<"->";
		curr=curr->next;
	}
	cout<<curr->data<<endl;
	return ;
}

int countNodes(node *head)
{
	if(head==NULL)
		return 0;

	int count=0;
	node *curr=head;
	while(curr->next!=head)
	{
		count++;
		curr=curr->next;
	}
	count++;
	return count;
}

void divideCircularList(node *head,node* &head1,node* &head2,int totalnodes)
{
	if(head==NULL)
		return;
	node *temp=head;
	head1=head;
	if(totalnodes%2==1)
	{
		for(int i=0;i<totalnodes/2;i++)
		head=head->next;
	}
	else
	{
		for(int i=0;i<totalnodes/2-1;i++)
		head=head->next;
	}
	
	
	head2=head->next;

	head->next=head1;

	head=head2;

	while(head->next!=temp)
		head=head->next;
	head->next=head2;

	return;
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

	if(head)
	{
		node *curr=head;
		while(curr->next)
			curr=curr->next;
		curr->next=head;	
	}
	
	printCircularList(head);
	int totalnodes=countNodes(head);
	node *head1=NULL,*head2=NULL;
	divideCircularList(head,head1,head2,totalnodes);
	printCircularList(head1);
	printCircularList(head2);
	return 0;
}