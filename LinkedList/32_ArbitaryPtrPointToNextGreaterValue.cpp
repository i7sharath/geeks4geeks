#include <bits/stdc++.h>

using namespace std;

struct node
{	
	int data;
	struct node *next;
	struct node *arbit;
};
	
void insert(node* &head,int val)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	newnode->arbit=NULL;
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

void printListArbitary(node *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		if(head->arbit)
			cout<<head->arbit->data;
		head=head->next;
		cout<<endl;
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
		head=head->arbit;
	}
	return count;
}

struct node *merge(node *head1,node *head2)
{
	node *anshead=NULL,*anscurr=NULL;
	while(head1 && head2)
	{
		if(head1->data <= head2->data)
		{
			if(anshead==NULL)
			{
				anshead=head1;
				anscurr=anshead;
			}
			else
			{	
				anscurr->arbit=head1;
				anscurr=anscurr->arbit;
			}
			head1=head1->arbit;
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
				anscurr->arbit=head2;
				anscurr=anscurr->arbit;
			}
			head2=head2->arbit;
		}
	}

	if(head1)
	{
		if(anshead==NULL)
			anshead=head1;
		else
			anscurr->arbit=head1;
	}

	if(head2)
	{
		if(anshead==NULL)
			anshead=head2;
		else
			anscurr->arbit=head2;
	}
	return anshead;
}

node *mergesort(node *head)
{
	if(head==NULL || head->arbit==NULL)
		return head;

	node *head1=head,*head2;
	int count=countNodes(head);

	for(int i=0;i<count/2-1;i++)
		head=head->arbit;


	head2=head->arbit;
	head->arbit=NULL;
	head1=mergesort(head1);
	head2=mergesort(head2);
	head=merge(head1,head2);
	return head;
}

node *populateArbitaryPointer(node *head)
{
	if(head==NULL || head->next==NULL)
		return head;
	node *currhead=head;
	while(currhead)
	{
		currhead->arbit=currhead->next;
		currhead=currhead->next;
	}
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
	head=populateArbitaryPointer(head);
	node *head1=mergesort(head);
	printListArbitary(head);
	return 0;
}