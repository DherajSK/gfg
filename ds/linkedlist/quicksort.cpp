#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
typedef struct node Node;
node* getTail(node* curr)
{
    while(curr!=NULL && curr->next!=NULL)
        curr=curr->next;
    return curr;
}

node* partition(node *head, node *end,node **newHead,node **newEnd)
{
    Node *pivot=end;
    Node *prev=NULL;
    Node *curr=head;
    Node *tail=pivot;
    
    while(curr!=pivot)
    {
        if(curr->data<pivot->data)
        {
            if((*newHead)==NULL)
                (*newHead)=curr;
            prev=curr;
            curr=curr->next;
        }
        
        else
        {
            if(prev)
                prev->next=curr->next;
            Node *temp=curr->next;
            curr->next=NULL;
            tail->next=curr;
            tail=curr;
            curr=temp;
        }
    }
    if((*newHead)==NULL)
        (*newHead)=pivot;
        
    (*newEnd)=tail;
        
    return pivot;
    
    
}

Node* quickSortRec(node *head, node *end)
{
    if(!head||head==end)
        return head;
    
    node *newHead=NULL,*newEnd=NULL;
    node *pivot=partition(head,end,&newHead,&newEnd);
    
    if(pivot!=newHead)
    {
        Node *temp=newHead;
        while(temp->next!=pivot)
            temp=temp->next;
        
        temp->next=NULL;
        
        newHead=quickSortRec(newHead,temp);
        
        temp=getTail(newHead);
        temp->next=pivot;
    }
    pivot->next=quickSortRec(pivot->next,newEnd);
    return newHead;
}

void quickSort(struct node **headRef) 
{
    (*headRef)=quickSortRec(*headRef,getTail(*headRef));
}
