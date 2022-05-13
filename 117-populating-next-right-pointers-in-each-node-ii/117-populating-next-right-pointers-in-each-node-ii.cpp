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
        
            Ok so Basic BFS and then change the next pointer at every_level !!!
        
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
            int v_n = v.size();
                
            
                for(int i = 0 ; i < v_n - 1 ; i++)
                {
                    // cout<<v[i]->val << " " <<v[i + 1]->val << endl;
                    v[i]->next = v[i + 1];
                }
                
                v[v_n - 1]->next = NULL;
        }
        
        return root;
    }
};