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
    
    bool checkPathSum(TreeNode* root, int targetSum)
    {
        //Base Case 
        
        if(root == NULL) return false;
        
        if(!root->left && !root->right)
        {
            return root->val == targetSum;
        }
        
        bool lh = checkPathSum(root->left , targetSum - root->val);
        if(lh == true) return true;
        
        bool rh = checkPathSum(root->right , targetSum - (root->val));
        if(rh == true) return true;
        
        return lh || rh;
            
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        
        if(root == NULL)
        {
            
            return false;
        }
        return checkPathSum(root , targetSum);
    }
};