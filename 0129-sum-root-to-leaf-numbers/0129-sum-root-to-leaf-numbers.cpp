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
    
    
    void f(TreeNode* root , int& ans , int temp)
    {
        if(!root) return;
        
        if(!root->left && !root->right)
        {            
            ans = ans + ((temp * 10) + root->val);
            return;
        }
        
        temp = temp * 10 + root->val;
    
        f(root->left , ans ,  temp);
        f(root->right , ans ,  temp);
    }
    
    int sumNumbers(TreeNode* root) {
        
        int temp = 0;  
        int ans = 0;
        f(root , ans , temp);
        
        return ans;
    }
};