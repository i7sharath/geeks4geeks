/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

void sortList(Node** head)
{
    if((*head)==NULL || (*head)->next==NULL)
        return;
    
    Node *currhead=*head,*prev=*head;
    currhead=currhead->next;
    while(currhead)
    {
        if(currhead->data < 0)
        {
            Node *temp=currhead;
            currhead=currhead->next;
            prev->next=temp->next;
            temp->next=*head;
            *head=temp;
        }
        else
        {
            prev=currhead;
            currhead=currhead->next;
        }
    }
    return;
}
