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
    
    int f(TreeNode* root , int currMin , int currMax)
    {
        if(root == NULL)
        {
            return currMax - currMin;
        }
        
        currMax = max(currMax , root->val);
        currMin = min(currMin  , root->val);
        
        int left = f(root->left , currMin , currMax);
        int right = f(root->right , currMin , currMax);
        
        return max(left , right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        
        return f(root , root->val , root->val);
    }
};