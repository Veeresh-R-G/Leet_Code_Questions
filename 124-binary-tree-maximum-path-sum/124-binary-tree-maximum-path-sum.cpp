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
    
    int maxPathSum(TreeNode* root , int& maxi)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int lh = max(maxPathSum(root->left , maxi) , 0);
        int rh = max(maxPathSum(root->right , maxi) , 0);
        
        
        maxi = max(maxi , root->val + lh + rh);
        
        return root->val + max(lh , rh);
        
    }
    int maxPathSum(TreeNode* root) {
     
        int maxi = INT_MIN;
        int tempAns = maxPathSum(root , maxi);
        
        return maxi;
        
    }
};