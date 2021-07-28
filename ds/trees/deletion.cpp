#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
struct Node* deletionBT(struct Node* root, int key);
void inn(Node *node)
{
    if(node==NULL)
        return;
    
    inn(node->left);
    cout<<node->data<<" ";
    inn(node->right);
}

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k;
        scanf("%d ",&k);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		root=deletionBT(root,k);
		inn(root);
		cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*
Structre of the node of the tree is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// you are required to complete this function
void deletedeepest(Node *root, Node *dNode)
{
    queue<Node *> q;
    q.push(root);
    Node *temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if (temp == dNode) {
            temp = NULL;
            delete (dNode);
            return;
        }
        if(temp->right)
        {
            if(temp->right==dNode)
            {
                temp->right=NULL;
                delete(dNode);
                return;
            }
            else
                q.push(temp->right);
            
        }
        if(temp->left)
        {
            if(temp->left==dNode)
            {
                temp->left=NULL;
                delete(dNode);
                return;
            }
            else 
                q.push(temp->left);
        }
    }
}
struct Node* deletionBT(struct Node* root, int key)
{
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL)
        if(root->data==key)
            return NULL;
        else
            return root;
    queue<Node *> q1;
    q1.push(root);
    Node *temp;
    Node *del=NULL;
    while(!q1.empty())
    {
        temp=q1.front();
        q1.pop();
        if(temp->data==key)
            del=temp;
        if(temp->left)
            q1.push(temp->left);
        if(temp->right)
            q1.push(temp->right);
    }
    if(temp==del)
    {
            deletedeepest(root,temp);
            return root;
    }
    if(del!=NULL)
    {
        int x=temp->data;
        deletedeepest(root,temp);
        del->data=x;
    }
    
    return root;
    
}