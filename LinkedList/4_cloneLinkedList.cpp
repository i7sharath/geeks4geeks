/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
       
        map<RandomListNode*,RandomListNode*> m;
        map<RandomListNode*,RandomListNode*> :: iterator it;
        RandomListNode *anshead=NULL,*anscurr=NULL,*currhead=head;
        if(head==NULL)
            return anshead;
      
        while(currhead)
        {
            RandomListNode *newNode=(RandomListNode*)malloc(sizeof(RandomListNode));
            newNode->label=currhead->label;
            m.insert(pair<RandomListNode*,RandomListNode*>(currhead,newNode));
            currhead=currhead->next;
        }
        
        currhead=head;
        anscurr=m[currhead];
        anshead=anscurr;
        currhead=head;
        while(currhead)
        {
            anscurr->next=m[currhead->next];
            anscurr->random=m[currhead->random];
            currhead=currhead->next;
            if(currhead==NULL)
                anscurr->next=NULL;
            anscurr=anscurr->next;
           
        }
        return anshead;
    }
};