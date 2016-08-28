#include <bits/stdc++.h>
#include <cstring>

using namespace std;

struct node
{	
	char *data;
	struct node *next;
};
	
void insert(node* &head,char *val)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data=(char *)malloc(sizeof(char)*strlen(val)+1);
	strcpy(newnode->data,val);

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
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
	return;
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

string getAstringreverse(node *head)
{
	string str="";
	while(head)
	{
		string s=head->data;
		reverse(s.begin(),s.end());
		str+=s;
		head=head->next;
	}
	return str;
}

string getAstring(node *head)
{
	string str="";
	while(head)
	{
		str+=(head->data);
		head=head->next;
	}
	return str;
}

int CheckPalindrome(node *head)
{
	string str=getAstring(head);
	reverse(head);
	string temp=getAstringreverse(head);
	if(str==temp)
		return 1;
	else
		return 0;
}

int main()
{
	struct node *head=NULL;
	int n;
	cin>>n;
	char *val=(char *)malloc(sizeof(char)*100);
	for(int i=0;i<n;i++)
	{
		cin>>val;
		insert(head,val);
	}
	
	printList(head);
	int flag=CheckPalindrome(head);
	if(flag)
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;

	return 0;
}