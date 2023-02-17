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
    
    TreeNode* prev = NULL;
    int ans = INT_MAX;
    void f(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        
        f(root->left);
        if(prev)
        {
            ans = min(ans , abs(prev->val - root->val));
          
        }
        
        prev = root;
        
        f(root->right);
    }
        
    
    int getMinimumDifference(TreeNode* root) {
        
        
        f(root);
        
        return ans;
        
    }
};