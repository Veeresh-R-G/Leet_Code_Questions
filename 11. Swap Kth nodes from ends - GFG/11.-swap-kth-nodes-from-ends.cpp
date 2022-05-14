// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
int len(Node*head)
{
    if(head == NULL)
    {
        return 0;
    }
    
    return 1 + len(head->next);
}
Node *swapkthnode(Node* head, int n, int k)
{
    Node* start = head;
    Node* end = head;
    Node* prev_start = NULL;
    Node* prev_end = NULL;
    
    if(k>n )
        return head;
    //Moving start ptr
    for(int i = 1; i<k; i++)
    {
        prev_start = start;
        start = start->next;
    }
    
    //Moving end ptr
    for(int i = 1; i<n-k+1; i++)
    {
        prev_end = end;
        end = end->next;
    }
    
    if(prev_start != NULL)
        prev_start->next = end;
    if(prev_end != NULL)
        prev_end->next = start;
    
    Node *temp = end->next;
    end->next = start->next;
    start->next = temp;
    
    if(k == 1)
        head = end;
    if(k == n)
        head = start;
    return head;
}
