#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left,*right;
};

TreeNode *createNewNode(int data)
{
	if(data==-1)
		return NULL;
	TreeNode *newNode=(TreeNode*)malloc(sizeof(TreeNode));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

TreeNode *createTree(TreeNode *root,vector<int> &vec)
{
	int n=vec.size();
	if(n==0)
		return NULL;

	queue<TreeNode*> q;
	root=createNewNode(vec[0]);
	q.push(root);
	int i=1;
	while(i<n && !q.empty())
	{
		TreeNode *temp=q.front();
		q.pop();
	
		temp->left=createNewNode(vec[i]);
		if(temp->left)
			q.push(temp->left);
		i++;
		
		if(i>=n)
			break;
		temp->right=createNewNode(vec[i]);
		i++;
		if(temp->right)
			q.push(temp->right);

	}
	return root;
}

void inorder(TreeNode *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	return;
}

void SerializeHelper(TreeNode *root,string &data)
{
	if(root==NULL)
	{
		data+="null ";
		return;
	}
	data+=to_string(root->data)+" ";
	SerializeHelper(root->left,data);
	SerializeHelper(root->right,data);
	return;
}

string serialize(TreeNode *root)
{
	string data;
	if(root==NULL)
		return data;
	SerializeHelper(root,data);
	return data;
}

TreeNode *DeserializeHelper(vector<string>&vec,int &index)
{
    if(vec[index]=="null")
    {
        index++;
        return NULL;
    }
    TreeNode *root=(struct TreeNode*)malloc(sizeof(TreeNode));
    root->data=stoi(vec[index++]);
    root->left=DeserializeHelper(vec,index);
    root->right=DeserializeHelper(vec,index);
    return root;
}

TreeNode* Deserialize(string data) 
{
    if(data.size()==0)
        return NULL;
    stringstream ss(data);
    vector<string> vec;
    string word;
    while(ss>>word)
        vec.push_back(word);
    int index=0;
    TreeNode *root=DeserializeHelper(vec,index);
    return root;
}

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		cin>>vec[i];
	TreeNode *root1=NULL;
	root1=createTree(root1,vec);
	string data=serialize(root1);
	cout<<data<<endl;
	TreeNode *root=Deserialize(data);
	inorder(root);
	cout<<endl;
	return 0;	
}
