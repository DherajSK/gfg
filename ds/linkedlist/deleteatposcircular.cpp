
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}



void displayList(Node *head)
{
    Node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
}


 // } Driver Code Ends
//User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};
*/

Node * deleteAtPosition(Node *head,int pos)
{
    Node *temp1=head;
    Node *temp2=head->next;
    int count=0;
    if(pos==1)
    {
        while(temp1->next!=head)
            temp1=temp1->next;
            
        temp1->next=temp2;
        delete head;
        return temp2;
    }
   
    for(int i=0;i<pos-2;i++)
        temp1=temp1->next;
    
    temp2=temp1->next;
    temp1->next=temp1->next->next;
    delete temp2;
    return head;
    
    
}


// { Driver Code Starts.




void makeCircular(Node * head)
{
    Node * temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=head;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail = NULL;
	    int x;
	    cin >> x;
	    head = new Node(x);
	    tail = head;
	    for(int i=0;i<n-1;i++)
	    {
	        cin>>x;
	        tail -> next = new Node(x);
	        tail = tail -> next;
	    }
	    
	    
	    int pos;
	    cin>>pos;

	    makeCircular(head);
	    
	  
	    head=deleteAtPosition(head,pos);
	    
	    displayList(head);
 
	    cout<<endl;
	}
	return 0;
}
