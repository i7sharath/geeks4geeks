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

node *sortAscending(node *head)
{
	node *p=head,*q;
	while(p->next)
	{
		q=p;
		while(q && q->next)
		{
			if(q->data > q->next->data)
				swap(q->data,q->next->data);
			q=q->next;
		}
		p=p->next;
	}
	return head;
}

node *sortDescending(node *head)
{
	node *p=head,*q;
	while(p->next)
	{
		q=p;
		while(q && q->next)
		{
			if(q->data < q->next->data)
				swap(q->data,q->next->data);
			q=q->next;
		}
		p=p->next;
	}
	return head;
}

void tripletSum(node *head1,node *head2, node *head3,int sum)
{
	node *a=head1;
	while(a)
	{
		node *b=head2,*c=head3;
		while(b && c)
		{
			int val=(a->data)+(b->data)+(c->data);
			if(val==sum)
			{
				cout<<a->data<<" "<<b->data<<" "<<c->data<<endl;
				return;
			}
			else if(val<sum)
				b=b->next;
			else
				c=c->next;
		}
		a=a->next;
	}
	return;
}

int main()
{
	struct node *head1=NULL,*head2=NULL,*head3=NULL;
	int n1,n2,n3;
	cin>>n1;
	for(int i=0;i<n1;i++)
	{
		int val;
		cin>>val;
		insert(head1,val);
	}

	cin>>n2;
	for(int i=0;i<n2;i++)
	{
		int val;
		cin>>val;
		insert(head2,val);
	}

	cin>>n3;
	for(int i=0;i<n3;i++)
	{
		int val;
		cin>>val;
		insert(head3,val);
	}
	int sum;
	cin>>sum;
	head2=sortAscending(head2);
	head3=sortDescending(head3);
	tripletSum(head1,head2,head3,sum);
	return 0;
}

