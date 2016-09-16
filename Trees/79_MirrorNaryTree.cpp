#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
	int data;
	vector<TreeNode*> child;
};

TreeNode *newNode(int data)
{
	TreeNode *temp=new TreeNode;
	temp->data=data;
	return temp;
}


void levelOrderTraversal(TreeNode *root)
{
	if(root==NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		int n=q.size();
		while(n)
		{
			TreeNode *temp=q.front();
			q.pop();
			cout<<temp->data<<" ";
			for(int i=0;i<temp->child.size();i++)
				q.push(temp->child[i]);	
			n--;
		}
		cout<<endl;
	}
	return;
}

void mirrorTree(TreeNode *root)
{
	if(root==NULL)
		return; 
	reverse(root->child.begin(),root->child.end());
	for(int i=0;i<root->child.size();i++)
		mirrorTree(root->child[i]);
	return;
}

int main()
{
	TreeNode *root = newNode(10);
    (root->child).push_back(newNode(2));
    (root->child).push_back(newNode(34));
    (root->child).push_back(newNode(56));
    (root->child).push_back(newNode(100));
    (root->child[1]->child).push_back(newNode(1));
    (root->child[3]->child).push_back(newNode(7));
    (root->child[3]->child).push_back(newNode(8));
    (root->child[3]->child).push_back(newNode(9));

    levelOrderTraversal(root);

    mirrorTree(root);
    levelOrderTraversal(root);
	return 0;
}