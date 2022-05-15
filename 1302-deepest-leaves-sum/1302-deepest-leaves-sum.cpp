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
    int sum = 0;
    int max(int a , int b)
    {
        return a>= b ? a : b;
    }
    int height(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return 1 + max(lh , rh);
    }
    
    void levelOrder_recur(TreeNode* root , int h)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(h == 1)
        {
            sum+=root->val;
            return;
        }
        
        levelOrder_recur(root->left , h - 1);
        levelOrder_recur(root->right , h - 1);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        
        if(root == NULL)
        {
            return 0;
        }
        
        int h = height(root);
        
        levelOrder_recur(root, h);
        
        return sum;
    }
    
    
    
};