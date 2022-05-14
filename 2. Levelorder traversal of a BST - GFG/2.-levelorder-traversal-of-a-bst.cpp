// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNewNode(int value) {
    Node *temp = new Node;
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

Node *newNode(Node *root, int data) {
    if (root == NULL)
        root = createNewNode(data);
    else if (data < root->data)
        root->left = newNode(root->left, data);
    else
        root->right = newNode(root->right, data);
    return root;
}


 // } Driver Code Ends
// User function Template for C++

// Function to return the level order traversal of a BST.
#include<queue>
vector<int> levelOrder(struct Node* node) {
    // code here
    
    if(node == NULL)
    {
        return {};
    }
    queue<Node*> q;
    q.push(node);
    vector<int> v;
    while(q.empty() == false)
    {
        Node* f = q.front();
        q.pop();
        
        v.push_back(f->data);
        
        if(f->left)
        {
            q.push(f->left);
        }
        
        if(f->right)
        {
            q.push(f->right);
        }
    }
    
    return v;
}

// { Driver Code Starts.

int main() {

    int testcases;
    cin >> testcases;
    while (testcases--) {
        Node *root = NULL;
        int sizeOfArray;
        cin >> sizeOfArray;
        int arr[sizeOfArray];

        for (int i = 0; i < sizeOfArray; i++) cin >> arr[i];

        for (int i = 0; i < sizeOfArray; i++) {
            root = newNode(root, arr[i]);
        }

        vector<int> res = levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends