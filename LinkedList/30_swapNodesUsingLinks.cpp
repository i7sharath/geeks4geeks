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

void swapNodes(node * &head,int x,int y)
{
	if(head==NULL ||(x==y))
		return;
	
	node *currX=head,*prevX=NULL,*currY=head,*prevY=NULL;

	while(currX && currX->data!=x)
	{
		prevX=currX;
		currX=currX->next;
	}

	while(currY && currY->data!=y)
	{
		prevY=currY;
		currY=currY->next;
	}

	if(currX==NULL || currY==NULL)
		return;

	if(prevX)
		prevX->next=currY;
	else
		head=currY;

	if(prevY)
		prevY->next=currX;
	else
		head=currX;

	swap(currY->next,currX->next);
	return;
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
	int x,y;
	cin>>x>>y;
	swapNodes(head,x,y);
	printList(head);

	return 0;
}