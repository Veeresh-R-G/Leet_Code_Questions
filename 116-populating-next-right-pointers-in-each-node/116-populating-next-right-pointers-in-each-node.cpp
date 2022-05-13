/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        
        /*
        
            Again BFS and then change next pointer of every Node at every Level
        
        */
        
        if(root == NULL)
        {
            return root;
        }
        
        
        queue<Node*> q;
        vector<Node*> v;
        
        q.push(root);
        
        
        while(!q.empty())
        {
            
            int n = q.size();
            v = {};
            //this loop runs for all nodes in one particular level !!
            for(int i = 0 ; i < n ; i++)
            {
                Node* f = q.front();
                q.pop();
                
                if(f->left)
                {
                    q.push(f->left);
                }
                
                if(f->right)
                {
                    q.push(f->right);
                }
                
                v.push_back(f);                
            }
            
            for(int i = 0 ; i < v.size() - 1 ; i++)
            {
                v[i]->next = v[i + 1];
            }
            
            v[v.size() - 1] = NULL;
        }
        
        return root;
        
    }
};