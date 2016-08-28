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

struct node *mergeList(node *head1,node *head2,node *head3)
{
	node *anshead3=NULL;
	while(head1 && head2)
	{
		if(head1->data==head2->data)
		{
			node *newNode=(node *)malloc(sizeof(node));
			newNode->data=head1->data;
			newNode->next=NULL;
			if(anshead3==NULL)
			{
				head3=newNode;
				anshead3=head3;
			}
			else
			{
				head3->next=newNode;
				head3=head3->next;
			}
			head1=head1->next;
			head2=head2->next;
		}
		else if(head1->data < head2->data)
		{
			node *newNode=(node *)malloc(sizeof(node));
			newNode->data=head1->data;
			newNode->next=NULL;
			if(anshead3==NULL)
			{
				head3=newNode;
				anshead3=head3;
			}
			else
			{
				head3->next=newNode;
				head3=head3->next;
			}
			head1=head1->next;
		}
		else
		{
			node *newNode=(node *)malloc(sizeof(node));
			newNode->data=head2->data;
			newNode->next=NULL;
			if(anshead3==NULL)
			{
				head3=newNode;
				anshead3=head3;
			}
			else
			{
				head3->next=newNode;
				head3=head3->next;
			}
			head2=head2->next;
		}
	}

	if(head1)
	{
		if(anshead3==NULL)
			anshead3=head1;
		else
			head3->next=head1;
	}

	if(head2)
	{
		if(anshead3==NULL)
			anshead3=head2;
		else
			head3->next=head2;
	}
	head3=anshead3;
	return head3;
}

int main()
{
	struct node *head1=NULL,*head2=NULL,*head3=NULL;
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		int val;
		cin>>val;
		insert(head1,val);
	}

	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		insert(head2,val);
	}
	
	printList(head1);
	printList(head2);
	head3=mergeList(head1,head2,head3);
	printList(head3);
	
	return 0;
}