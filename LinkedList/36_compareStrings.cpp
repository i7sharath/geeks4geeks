/* Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
}; */

// Compare two strings represented as linked lists
int compare(Node *list1, Node *list2) 
{
     if(list1==NULL && list2==NULL)
        return 0;
    if((list1==NULL && list2!=NULL)||(list1!=NULL && list2==NULL))
        return 1;
        
    while(list1 && list2)
    {
        if(list1->c!=list2->c)
        {
            if(list1->c > list2->c)
                return 1;
            else
                return -1;
        }
        list1=list1->next;
        list2=list2->next;
    }
    
    if(list1)
        return 1;
    if(list2)
        return -1;
    return 0;
}