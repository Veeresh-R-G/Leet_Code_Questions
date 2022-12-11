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
    
    //My solution
    long long totalSum;
    long long MOD = 1e9 + 7;
    
    
    long long sum(TreeNode* root)
    {
        if(!root) return 0;
        
        return root->val + sum(root->left) + sum(root->right);
    }
    
    long long maxPro(TreeNode* root , long long& ans)
    {
        if(!root) return 0;
        
        int currSum = root->val + maxPro(root->left , ans) + maxPro(root->right , ans);
        
        ans = max(ans , (totalSum - currSum) * currSum);
        
        return currSum;
        
    }
    int maxProduct(TreeNode* root) {
        
        
        totalSum = sum(root);
        
        long long ans = -1e8;
        
        maxPro(root , ans);
        return ans % (MOD);
    }
};