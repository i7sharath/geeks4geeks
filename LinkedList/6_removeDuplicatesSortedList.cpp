#include <bits/stdc++.h>

using namespace std;

struct node
{	
	int data;
	struct node *next;
};
	
void insert(node* &head,int val)
{
	if(head==NULL)
		return head;
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

struct node *removeDuplicates(node* head)
{
	node *curr=head;
	node *temp;
	while(curr->next)
	{
		if(curr->data==curr->next->data)
		{
			temp=curr->next;
			curr->next=curr->next->next;
			free(temp);
		}
		else
			curr=curr->next;
	}
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
	head=removeDuplicates(head);
	printList(head);

	return 0;
}