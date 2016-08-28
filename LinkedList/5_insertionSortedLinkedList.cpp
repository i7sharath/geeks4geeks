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

struct node *createNode(int data)
{
	node *newNode=(node*)malloc(sizeof(node));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}


struct node *insertDataInsortedList(node* head,int data)
{
	if(head==NULL)
	{
		head=createNode(data);
		return head;
	}
	if(head->data > data)
	{
		node *newNode=createNode(data);
		newNode->next=head;
		head=newNode;
		return head;
	}

	node *curr=head,*prev=NULL;
	node *temp=createNode(data);
	while(curr)
	{
		if(curr->data < data)
		{
			prev=curr;
			curr=curr->next;
		}
		else
		{
			temp->next=prev->next;
			prev->next=temp;
			return head;
		}
	}

	prev->next=temp;
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
	int data;
	cin>>data;
	head=insertDataInsortedList(head,data);
	printList(head);

	return 0;
}