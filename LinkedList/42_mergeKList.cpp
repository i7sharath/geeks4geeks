/*Linked list node structure
struct node
{
    int data;
    struct node* next;
};*/ 

node *merge(node *head1,node *head2)
{
    node *anshead=NULL,*anscurr=NULL;
    while(head1 && head2)
    {
        if(head1->data <=head2->data)
        {
            if(anshead==NULL)
            {
                anshead=head1;
                anscurr=anshead;
            }
            else
            {
                anscurr->next=head1;
                anscurr=anscurr->next;
            }
            head1=head1->next;
        }
        else
        {
            if(anshead==NULL)
            {
                anshead=head2;
                anscurr=anshead;
            }
            else
            {
                anscurr->next=head2;
                anscurr=anscurr->next;
            }
            head2=head2->next;
        }
    }
    
    if(head1)
    {
        if(anshead==NULL)
            anshead=head1;
        else
            anscurr->next=head1;
    }
    
    if(head2)
    {
        if(anshead==NULL)
            anshead=head2;
        else
            anscurr->next=head2;
    }
    return anshead;
}

node * mergeKList(node *arr[],int N)
{
    node *head=NULL;
    if(N<0)
        return head;
    if(N==0)
    {
        head=arr[0];
        return head;
    }
    head=arr[0];
    for(int i=1;i<=N;i++)
    {
        head=merge(head,arr[i]);
    }
    return head;
}