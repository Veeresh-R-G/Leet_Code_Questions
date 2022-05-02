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
    int max(int a , int b)
    {
        return a>=b ? a : b;
    }
    
    /*
    Time Complexity : O(n)
    Space Complexity : O(h)
    
    h--> Height of tree : log(n) where n is the number of nodes
    */
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return 1 + max(lh , rh);
    }
};