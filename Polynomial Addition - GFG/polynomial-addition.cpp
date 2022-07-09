// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node* new_node = new Node(new_data, new_data1);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    
    while (temp != NULL)
    {
       printf("%d %d ", temp->coeff, temp->pow);
       temp  = temp->next;
    }
}

Node* addPolynomial(Node *p1, Node *p2);


void create_node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}
 

/* Driver program to test above function*/

 // } Driver Code Ends
/* Structure of Node used
struct Node
{
    int coeff;
    int pow;
    struct Node* next;
    
    Node(int c, int p){
        coeff = c;
        pow = p;
        next = NULL;
    }
    
};
*/

class Solution{
  public:
    /* The below method print the required sum of polynomial
    p1 and p2 as specified in output  */
    /*
    
    given polynomials are already sorted in descending order of powers
    
    */
    Node* addPolynomial(Node *p1, Node *p2)
    {
        //Your code here
        Node* temp1 = p1;
        Node* temp2 = p2;
        
        Node* ans = new Node(-1 , -1);
        Node* temp3 = ans;
        while(temp1 && temp2)
        {
            int p1 = temp1->pow; //2 //1
            int c1 = temp1->coeff; 
            
            int p2 = temp2->pow; // 3
            int c2 = temp2->coeff; // 1
            
            if(p1 == p2)
            {
                Node* node = new Node(c1 + c2 , p1);
                temp3->next = node;
                temp3 = temp3->next;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            
            else if(p1 > p2)
            {
                Node* node = new Node(c1 , p1);
                temp3->next = node;
                temp3 = temp3->next;
                temp1 = temp1->next;
            }
            else
            {
                Node* node = new Node(c2 , p2); //Node(1 ,3 )
                temp3->next = node;
                temp3 = temp3->next;
                temp2 = temp2->next;
            }
        }
        
        while(temp1)
        {
            Node* node = new Node(temp1->coeff , temp1->pow);
            temp3->next = node;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        
        while(temp2)
        {
            Node* node = new Node(temp2->coeff , temp2->pow);
            temp3->next = node;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
        
        return ans->next;
    }
};


// { Driver Code Starts.
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1  = NULL,*tail2 = NULL;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly1,&tail1,x,y);
        }
        
         int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            	append(&poly2,&tail2,x,y);
        }
        Solution obj;
        Node *sum = obj.addPolynomial(poly1,poly2);
        for(Node* ptr=sum ; ptr ; ptr=ptr->next  )
        {
            // printing polynomial
            cout<< ptr->coeff << "x^" << ptr->pow;
            if(ptr->next) cout<<" + ";
        }
        cout<<endl;
       
    }

}
  // } Driver Code Ends