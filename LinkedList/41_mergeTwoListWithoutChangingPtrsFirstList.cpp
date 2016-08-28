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

void mergeTwoList(node* &head1,node* &head2)
{
	if((head1==NULL && head2==NULL)||(head2==NULL))
		return ;
	if(head1==NULL)
	{
		head1=head2;
		head2=NULL;
		return;
	}

	node *currhead1=head1,*currhead2=head2;
	while(currhead1 && currhead2)
	{
		if(currhead1->data >currhead2->data)
		{
			swap(currhead1->data,currhead2->data);
			while(currhead2 && currhead2->next && currhead2->data >currhead2->next->data)
			{
				swap(currhead2->data,currhead2->next->data);
				currhead2=currhead2->next;
			}
			currhead2=head2;
		}	
		else
			currhead1=currhead1->next;
	}
	return;
}

int main()
{
	struct node *head1=NULL,*head2=NULL;
	int m,n;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int val;
		cin>>val;
		insert(head1,val);
	}

	cin>>n;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		insert(head2,val);
	}	
	mergeTwoList(head1,head2);
	printList(head1);
	printList(head2);
	return 0;
}