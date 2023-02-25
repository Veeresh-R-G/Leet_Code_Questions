/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> ans;
    void f(Node* root)
    {
        if(!root)
        {
            return;
        }
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> child;
            for(int i = 0 ; i < n ; i++)
            {
                auto node = q.front();
                q.pop();
                
                child.push_back(node->val);
                
                for(auto child : node->children)
                {
                    q.push(child);
                }
            }
            
            ans.push_back(child);           
        }
        return;
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        
        
        
        f(root);
        
        return ans;
    }
};