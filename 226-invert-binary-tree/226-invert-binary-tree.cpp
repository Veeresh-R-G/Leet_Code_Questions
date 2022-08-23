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
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root) return NULL;
        
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            
            TreeNode* leftPart = front->left;
            TreeNode* rightPart = front->right;
            
            TreeNode* tempo = leftPart;
            front->left = rightPart;
            front->right = tempo;
            
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);            
            
        }
        
        return root;
    }
};