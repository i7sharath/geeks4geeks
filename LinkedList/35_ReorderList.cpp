/* Following is the Linked list node structure */
/*struct node
{
    int data;
    struct node* next;
};*/

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

void reverse(node* &head)
{
    node *curr=head,*prev=NULL,*nxt;
    while(curr)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
    return;
}

void reorderList(struct node* head) 
{
    if(head==NULL || head->next==NULL)
        return ;
    int count=countnodes(head);
    node *currhead=head,*head1=head,*head2;
    for(int i=0;i<count/2;i++)
        currhead=currhead->next;
   
    head2=currhead->next;
    currhead->next=NULL;
    reverse(head2);
    while(head1 && head2)
    {
        node *temp=head2;
        head2=head2->next;
        temp->next=head1->next;
        head1->next=temp; 
        head1=head1->next->next;
    }
    return;
}