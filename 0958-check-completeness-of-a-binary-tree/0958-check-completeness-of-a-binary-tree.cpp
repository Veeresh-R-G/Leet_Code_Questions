/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool bfs(TreeNode* root)
    {
          queue<TreeNode*> q;
        
        q.push(root);
        
        bool gotNull = false;
        while(!q.empty())
        {
            
            auto f = q.front();
            q.pop();
            if(f == NULL)
            {
                gotNull = true;
            }
            else
            {
                if(gotNull) return false;
                
                q.push(f->left);
                q.push(f->right);
            }
            
        }
        
        return true;
    }
    
    int len(TreeNode* root)
    {
        if(!root) return 0;
        
        return 1 + len(root->left) + len(root->right);
    }
    
    bool dfs(TreeNode* root , int node_ind , int length)
    {
        if(root == NULL) return true;
        
        if(node_ind > length) return false;
        
        return dfs(root->left, 2*node_ind , length) && dfs(root->right , (2 * node_ind) + 1 , length);
    }
    bool isCompleteTree(TreeNode* root) {
        
        
        int length = len(root);
        // return bfs(root);
        return dfs(root , 1 , length);
        
      
    }
};