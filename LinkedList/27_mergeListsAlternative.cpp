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

struct node *mergeListAlternatively(node *head1,node *head2)
{
	if(head1==NULL || head2==NULL)
		return head1;

	node *ans=head1;
	while(head1 && head2)
	{
		node *temp=head2;
		head2=head2->next;
		temp->next=head1->next;
		head1->next=temp;
		head1=head1->next->next;
	}

	return ans;
}

int main()
{
	struct node *head1=NULL,*head2=NULL;
	int m,n;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int val;
		cin>>val;
		insert(head1,val);
	}
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		insert(head2,val);
	}
	
	printList(head1);
	printList(head2);
	head1=mergeListAlternatively(head1,head2);
	printList(head1);
	return 0;
}