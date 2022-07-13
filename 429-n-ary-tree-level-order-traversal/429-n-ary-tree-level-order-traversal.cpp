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
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root == NULL) return {};
        vector<vector<int>> ans ={};
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            
            
            
            int l = q.size();
            
            vector<int> temp;
            for(int i = 0 ; i < l ; i++)
            {
                Node* front = q.front();
                
                
                
                int n = front->children.size();
                
                for(int i = 0 ; i < n ; i++)
                {
                    q.push(front->children[i]);
                }
                temp.push_back(front->val);
                q.pop();
                
                
            }
            ans.push_back(temp);
            
        }
        
        return ans;
    }
};