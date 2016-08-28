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

struct node *removeDuplicates(node *head)
{
	if(head==NULL)
		return NULL;
	
	map<int,int> m;
	node *curr=head,*prev=head;
	m[curr->data]=1;
	curr=curr->next;
	while(curr)
	{
		int val=curr->data;
		if(m.find(val)==m.end())
		{
			
			m[val]=1;
			prev=curr;
			curr=curr->next;
		}
		else
		{
			curr=curr->next;
			prev->next=curr;
		}
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