// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    if(head1 == NULL && head2)
    {
        return head2;
    }
    
    if(head1 && !(head2))
    {
        head1;
    }
    Node* ans = new Node(-1);
    Node* temp = ans;
    Node* t1 = head1;
    Node* t2 = head2;
    
    
    while(t1 && t2)
    {
        if(t1->data >= t2->data)
        {
            temp->next = new Node(t2->data);
            t2 = t2->next;
        }
        else if(t1->data < t2->data)
        {
            temp->next = new Node(t1->data);
            t1 = t1->next;
        }
        temp = temp -> next;
    }
    
    
    while(t1)
    {
        temp->next = new Node(t1->data);
        t1 = t1-> next;
        temp = temp->next;
    }
    
    while(t2)
    {
        temp->next = new Node(t2->data);
        t2 = t2->next;
        temp = temp->next;
    }
    
    return ans->next;
    
    
}