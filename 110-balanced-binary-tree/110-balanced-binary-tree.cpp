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
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int leftHeight = height(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = height(root->right);
        if(rightHeight == -1) return -1;
        
        if(abs(leftHeight - rightHeight) > 1) return -1;
        
        return 1 + max(leftHeight , rightHeight);
    }
    
    bool check(TreeNode* root)
    {
        if(root == NULL)
        {
            return true;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return abs(lh - rh) <= 1 && check(root->left) && check(root->right);
        
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL)
        {
            return true;
        }
        
        return height(root) == -1 ? false : true;
    }
};