/*
Given a linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. where a, b, c.. are consecutive data node of linked list. Examples :

Input:  1->2->3->4
Output: 1->3->2->4 

Input:  11->15->20->5->10
Output: 11->20->5->15->10
*/

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

node *zigZack(node* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    node *currhead=head;
    int flaggreater=0;
    while(currhead && currhead->next)
    {
        if(flaggreater==0)
        {
            if(currhead->data > currhead->next->data)
                swap(currhead->data,currhead->next->data);
            flaggreater=1;
        }
        else
        {
            if(currhead->data < currhead->next->data)
                swap(currhead->data,currhead->next->data);
            flaggreater=0;
        }
        currhead=currhead->next;
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
    head=zigZack(head);
    printList(head);
    return 0;
}

