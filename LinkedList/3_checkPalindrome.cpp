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

void reverseList(node* &head)
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

bool checkPlaindrome(node *head)
{
	node *head2=NULL;
	node *curr=head;
	int count=0;
	while(curr)
	{
		count++;
		curr=curr->next;
	}

	curr=head;
	for(int i=0;i<count/2;i++)
		curr=curr->next;

	head2=curr->next;
	curr->next=NULL;

	reverseList(head2);

	while(head && head2)
	{
		if(head->data!=head2->data)
			return false;
		head=head->next;
		head2=head2->next;
	}	
	return true;
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

	bool flag=checkPlaindrome(head);
	if(flag)
		cout<<"True"<<endl;
	else
		cout<<"false"<<endl;

	return 0;
}