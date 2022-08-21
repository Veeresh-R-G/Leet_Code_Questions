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
    
    int height(TreeNode* root , vector<int>& maxDia)
    {
        if(root == NULL) return 0;
        
        int lh = height(root->left , maxDia);
        int rh = height(root->right , maxDia);
        
        if(maxDia.size() == 0)
        {
            maxDia.push_back(lh + rh);
        }
        else
        {
            int top = maxDia[0];
            if(top < (lh + rh))
            {
                 maxDia[0] = (lh + rh); 
            }
        }
        
        return 1 + max(lh , rh);
    }
    
    
   
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        
        vector<int> ans = {};
        
        int h = height(root , ans);
        
        return ans[0];
        
        
    }
};