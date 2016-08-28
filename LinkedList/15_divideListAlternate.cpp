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

void AlternateList(node *head,node* &head1,node* &head2)
{
	if(head==NULL)
		return;

	node *curr=head;
	node *anshead2=NULL;
	while(curr && curr->next)
	{
		node *temp=curr->next;
		curr->next=curr->next->next;
		curr=curr->next;	
		if(head2==NULL)
		{
			head2=temp;
			anshead2=head2;
		}
		else 
		{	
			head2->next=temp;
			head2=head2->next;
		}
	}
	head2->next=NULL;
	head1=head;
	head2=anshead2;
	return ;
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
	node *head1=NULL,*head2=NULL;
	printList(head);
	AlternateList(head,head1,head2);
	printList(head1);
	printList(head2);
	

	return 0;
}