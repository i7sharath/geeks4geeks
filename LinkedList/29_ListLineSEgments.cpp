#include <bits/stdc++.h>

using namespace std;

struct node
{	
	int x,y;
	struct node *next;
};
	
void insert(node* &head,int x,int y)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->x=x;
	newnode->y=y;
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
		cout<<"("<<head->x<<","<<head->y<<")"<<" ";
		head=head->next;
	}
	cout<<endl;
	return;
}

struct node *DeleteMiddlePoints(node *head)
{
	if(head==NULL || head->next==NULL || head->next->next==NULL)
		return head;

	node *Nxt=head->next,*NxtNxt=head->next->next;

	if(head->y==Nxt->y)
	{
		while(NxtNxt && Nxt->y==NxtNxt->y)
		{
			//delete Nxt node
			node *temp=Nxt;
			head->next=NxtNxt;
			temp->next=NULL;
			free(temp);

			Nxt=NxtNxt;
			NxtNxt=NxtNxt->next;
		}
	}
	else if(head->x==Nxt->x)
	{
		while(NxtNxt && Nxt->x==NxtNxt->x)
		{
			//delete Nxt node
			node *temp=Nxt;
			head->next=NxtNxt;
			temp->next=NULL;
			free(temp);

			Nxt=NxtNxt;
			NxtNxt=NxtNxt->next;
		}
	}
	else
	{
		cout<<"Linked is not valid"<<endl;
		return NULL;
	}

	DeleteMiddlePoints(head->next);
	return head;
}

int main()
{
	struct node *head=NULL;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		insert(head,x,y);
	}
	
	printList(head);	
	head=DeleteMiddlePoints(head);
	printList(head);
	return 0;
}