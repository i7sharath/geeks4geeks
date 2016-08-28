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

int countnodes(node *head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}

node *rotateList(node *head,int k)
{
	int count=countnodes(head);
	if(count==k)
		return head;
	node *curr=head;
	for(int i=0;i<k-1;i++)
		curr=curr->next;

	node *curr2=curr->next;
	curr->next=NULL;
	node *ans=curr2;
	while(curr2->next)
		curr2=curr2->next;

	curr2->next=head;
	return ans;
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

	int k;
	cin>>k;
	head=rotateList(head,k);
	printList(head);
	return 0;
}