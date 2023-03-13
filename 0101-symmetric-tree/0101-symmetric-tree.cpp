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
    
    bool f(TreeNode* tree1 , TreeNode* tree2)
    {
        if(!tree1 && !tree2) return true;
        
        if((tree1 && !tree2) || (tree2 && !tree1) || (tree1->val != tree2->val)) return false;
        
        return f(tree1->left , tree2->right) && f(tree1->right , tree2->left);
        
        
    }
    
    bool isSymmetric(TreeNode* root) {
        
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        
        
        return f(l , r);
    }
};