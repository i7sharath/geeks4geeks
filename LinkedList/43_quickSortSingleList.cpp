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

node *partition(node *head,node *end,node *pivot,node* &newhead,node* &newend)
{
	node *prev=NULL,*currhead=head,*tail=pivot;
	while(currhead!=pivot)
	{
		if(currhead->data < pivot->data)
		{
			if(newhead==NULL)
				newhead=currhead;
			prev=currhead;
			currhead=currhead->next;
		}
		else
		{
			if(prev)
				prev->next=currhead->next;

			struct node *tmp = currhead->next;
            currhead->next = NULL;
            tail->next = currhead;
            tail = currhead;
            currhead = tmp;
		}
	}
	if(newhead==NULL)
		newhead=pivot;

	newend=tail;
	return newend;
}

node *quicksort(node *head,node *end)
{
	if(head==NULL || head==end)
		return head;

	node *newhead=NULL,*newend=NULL;
	node *pivot=partition(head,end,end,newhead,newend);
	if(newhead!=pivot)
	{
		node *tmp=newhead;
		while(tmp->next!=pivot)
			tmp=tmp->next;
		tmp->next=NULL;

		newhead=quicksort(newhead,tmp);

		tmp=newhead;
		while(tmp->next)
			tmp=tmp->next;
		tmp->next=pivot;
	}

	pivot->next=quicksort(pivot->next,newend);
	return newhead;
}

node *getSortList(node *head)
{
	node *end=NULL,*currhead=head;
	while(currhead->next)
		currhead=currhead->next;
	end=currhead;
	return quicksort(head,end);
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
	head=getSortList(head);
	printList(head);
	return 0;
}