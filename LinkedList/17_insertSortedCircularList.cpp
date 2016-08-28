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

node *insertSortedList(node *head,int val)
{
	node *newNode=(node*)malloc(sizeof(node));
	newNode->data=val;
	newNode->next=NULL;
	if(head==NULL)
	{
		head=newNode;
		newNode->next=head;
		return head;
	}

	if(head->data > val)
	{
		node *currhead=head;
		while(currhead->next!=head)
			currhead=currhead->next;
		currhead->next=newNode;
		newNode->next=head;
		head=newNode;
		return head;
	}

	node *prev=head;
	node *currhead=head->next;
	while(currhead->next!=head)
	{
		if(currhead->data > val)
		{
			newNode->next=currhead;
			prev->next=newNode;
			return head;
		}
		else
		{
			prev=currhead;
			currhead=currhead->next;
		}
	}

	newNode->next=head;
	currhead->next=newNode;
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

	if(head)
	{
		node *curr=head;
		while(curr->next)
			curr=curr->next;
		curr->next=head;	
	}
	
	printCircularList(head);

	int val;
	cin>>val;
	head=insertSortedList(head,val);
	printCircularList(head);
	return 0;
}