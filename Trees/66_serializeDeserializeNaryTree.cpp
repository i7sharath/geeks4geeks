#include <bits/stdc++.h>

using namespace std;

const int N=5;

struct TreeNode 
{
	int data;
	TreeNode *child[N];
};

TreeNode *newNode(int key)
{
    TreeNode *temp = new TreeNode;
    temp->data = key;
    for (int i = 0; i < N; i++)
        temp->child[i] = NULL;
    return temp;
}

TreeNode *createDummyTree()
{
    TreeNode *root = newNode(1);
    root->child[0] = newNode(2);
    root->child[1] = newNode(3);
    root->child[2] = newNode(4);
    root->child[0]->child[0] = newNode(5);
    root->child[0]->child[1] = newNode(6);
    root->child[2]->child[0] = newNode(7);
    root->child[2]->child[1] = newNode(8);
    root->child[2]->child[2] = newNode(9);
    root->child[2]->child[3] = newNode(10);
    root->child[0]->child[1]->child[0] = newNode(11);
    return root;
}

void traversal(TreeNode *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	for(int i=0;i<N;i++)
		traversal(root->child[i]);
	return;
}

void serialize(TreeNode *root,string &data)
{
	if(root==NULL)
		return;
	data+=to_string(root->data)+" ";
	for(int i=0;i<N && root->child[i];i++)
		serialize(root->child[i],data);
	data+=")";
	data+=" ";
	return;
}	

int deserialize(TreeNode *&root,vector<string> &vec,int &index)
{
	if(vec[index]==")")
	{
		index++;
		return 1;
	}
	root=(struct TreeNode*)malloc(sizeof(TreeNode));
	root->data=stoi(vec[index++]);
	for(int i=0;i<N ;i++)
	{
		if(index>=vec.size() || deserialize(root->child[i],vec,index))
			break;
	}
	return 0;
}

int main()
{
	TreeNode *root=createDummyTree();
	string data;
	serialize(root,data);
	cout<<data<<endl;
	vector<string> vec;
	stringstream ss(data);
	string word;
	while(ss >> word)
		vec.push_back(word);
	int index=0;
	TreeNode *root1;
	deserialize(root1,vec,index);
	traversal(root1);
	cout<<endl;
	return 0;
}