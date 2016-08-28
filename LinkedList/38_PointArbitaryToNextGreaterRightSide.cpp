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
    return;
}

node *ArbitaryNextGreaterRightSide(node *head)
{
	if(head==NULL || head->next==NULL)
		return head;
	reverse(head);
	node *maxnode=head,*currhead=head->next;
	while(currhead)
	{
		currhead->arbit=maxnode;
		if(currhead->data > maxnode->data)
			maxnode=currhead;
		currhead=currhead->next;
	}
	reverse(head);
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
	head=ArbitaryNextGreaterRightSide(head);
	printListArbitary(head);
	return 0;
}