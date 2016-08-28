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

node *saggregateEvenOddList(node *head)
{
	node *anseven=NULL,*ansodd=NULL,*evencurr=NULL,*oddcurr=NULL;
	while(head)
	{
		if(head->data%2==0)
		{
			if(anseven==NULL)
			{
				anseven=head;
				evencurr=anseven;
				head=head->next;
				evencurr->next=NULL;
			}
			else
			{
				evencurr->next=head;
				evencurr=evencurr->next;
				head=head->next;
				evencurr->next=NULL;
			}
		}
		else
		{
			if(ansodd==NULL)
			{
				ansodd=head;
				oddcurr=ansodd;
				head=head->next;
				oddcurr->next=NULL;
			}
			else
			{
				oddcurr->next=head;
				oddcurr=oddcurr->next;
				head=head->next;
				oddcurr->next=NULL;
			}
		}
	}
	evencurr->next=ansodd;
	return anseven;
}

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
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
		head=saggregateEvenOddList(head);

		while(head)
		{
			cout<<head->data<<" ";
			head=head->next;
		}
		cout<<endl;

		testcases--;
	}
	return 0;
}