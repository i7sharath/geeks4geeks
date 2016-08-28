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

void reverse(node* &head)
{
	node *curr=head,*prev=NULL,*nxt;
	while(curr)
	{
		nxt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nxt;
	}
	head=prev;
	return ;
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
				anscurr->next=head1;
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
			anscurr->next=head1;

	}
	if(head2)
	{
		if(anshead==NULL)
			anshead=head2;
		else
			anscurr->next=head2;
	}

	return anshead;
}

node *sortListAscendingDescending(node *head,int n)
{
	if(head==NULL || head->next==NULL)
		return head;

	node *head1=NULL,*head2=NULL;
	node *curr1,*curr2;
	int flaghead1=1;
	while(head)
	{
		if(flaghead1==1)
		{
			if(head1==NULL)
			{
				head1=head;
				curr1=head1;
			}
			else
			{
				curr1->next=head;
				curr1=curr1->next;
			}	
			flaghead1=0;
		}
		else
		{
			if(head2==NULL)
			{
				head2=head;
				curr2=head2;
			}
			else
			{
				curr2->next=head;
				curr2=curr2->next;
			}
			flaghead1=1;
		}
		head=head->next;
		
	}
	curr1->next=NULL;
	curr2->next=NULL;

	reverse(head2);
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
	head=sortListAscendingDescending(head,n);
	printList(head);
	return 0;
}