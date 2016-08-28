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
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
	return;
}

node *swapNodes(node *head,int n,int k)
{
	node *temp1,*temp2,*curr=head;
	for(int i=0;i<k-1;i++)
		curr=curr->next;

	temp1=curr;

	curr=head;
	for(int i=0;i<n-k;i++)
		curr=curr->next;

	temp2=curr;
	swap(temp1->data,temp2->data);
	return head;
}
	

int main()
{
	int testcases;
	cin>>testcases;
	while(testcases)
	{
		struct node *head=NULL;
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			int val;
			cin>>val;
			insert(head,val);
		}
		head=swapNodes(head,n,k);
		printList(head);
		testcases--;
	}
	return 0;
}