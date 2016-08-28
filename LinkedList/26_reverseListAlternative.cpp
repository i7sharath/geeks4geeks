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

struct node *reverseListAlternative(node *head,int k)
{
	if(head==NULL || head->next==NULL)
		return head;

	node *prev=NULL,*curr=head,*nxt;
	int count=0;
	while(curr && count<k)
	{
		count++;
		nxt=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nxt;
	}

	head->next=curr;
	count=0;
	while(curr && count<k-1)
	{
		curr=curr->next;
		count++;
	}

	if(curr)
		curr->next=reverseListAlternative(curr->next,k);
	return prev;
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

	int k;
	cin>>k;
	head=reverseListAlternative(head,k);
	printList(head);
	return 0;
}