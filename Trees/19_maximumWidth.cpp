/*  Structure of a Binary Tree 
struct Node
{
    int data;
    struct Node* left, *right;
}; */

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
    if(root==NULL)
        return 0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int maxval=1;
    int count=0;
    while(!q.empty())
    {
        Node *temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            if(!q.empty())
            {
                q.push(NULL);
                maxval=max(maxval,count);
                count=0;
            }
        }
        else
        {
            count++;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        maxval=max(maxval,count);
    }
    maxval=max(maxval,count);
    
    return maxval;
}
