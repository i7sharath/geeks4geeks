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

void intersection(struct node **head1, struct node **head2, struct node **head3)
{
    node *anshead=NULL;
    while(*head1 && *head2)
    {
        if((*head1)->data==(*head2)->data)
        {
            node *newNode=(node*)malloc(sizeof(node));
            newNode->data=(*head1)->data;
            newNode->next=NULL;
            if(*head3==NULL)
            {
               *head3=newNode;
                anshead=*head3;
            }
            else
            {
                (*head3)->next=newNode;
                *head3=(*head3)->next;
            }
            *head1=(*head1)->next;
            *head2=(*head2)->next;
        }
        else if((*head1)->data < (*head2)->data)
            *head1=(*head1)->next;
        else
            *head2=(*head2)->next;
    }
    *head3=anshead;
    return ;
}

int main()
{
	struct node *head1=NULL,*head2=NULL,*head=NULL;
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		int val;
		cin>>val;
		insert(head1,val);
	}

	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		insert(head2,val);
	}

	printList(head1);
	printList(head2);
	intersection(&head1,&head2,&head);
	printList(head);

	return 0;
}