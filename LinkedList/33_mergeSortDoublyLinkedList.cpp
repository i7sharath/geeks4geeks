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
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
	return;
}

int countNodes(node *head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}

	return count;
}	

node *merge(node *head1,node *head2)
{
	node *anshead=NULL,*anscurr=NULL;
	while(head1 && head2)
	{
		if(head1->data <=  head2->data)
		{
			if(anshead==NULL)
			{
				anshead=head1;
				anscurr=anshead;
			}
			else
			{
				anscurr->next=head1;
				head1->prev=anscurr;
				anscurr=anscurr->next;
			}
			head1=head1->next;
		}
		else
		{	
			if(anshead==NULL)
			{
				anshead=head2;
				anscurr=anshead;
			}
			else
			{
				anscurr->next=head2;
				head1->prev=anscurr;
				anscurr=anscurr->next;
			}
			head2=head2->next;
		}
	}

	if(head1)
	{
		if(anshead==NULL)
			anshead=head1;
		else
		{
			anscurr->next=head1;
			head1->prev=anscurr;
		}
	}

	if(head2)
	{
		if(anshead==NULL)
			anshead=head2;
		else
		{
			anscurr->next=head2;
			head2->prev=anscurr;
		}
	}
	return anshead;
}

struct node *mergesort(node *head)
{
	if(head==NULL || head->next==NULL)
		return head;

	node *head1=head,*head2;
	int count=countNodes(head);
	for(int i=0;i<count/2-1;i++)
		head=head->next;

	head2=head->next;
	head->next=NULL;
	head2->prev=NULL;

	head1=mergesort(head1);
	head2=mergesort(head2);
	head=merge(head1,head2);
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
	head=mergesort(head);
	printList(head);
	return 0;
}