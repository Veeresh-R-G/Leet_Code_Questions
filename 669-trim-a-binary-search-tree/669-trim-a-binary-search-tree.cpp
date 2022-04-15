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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(root == NULL){
            return NULL;
        }
        
        if(root->val < low){
            //ignore this side nodes 
            return trimBST(root->right , low , high);
        }
        else{
            //root->val > low 3 > 1
            root->left = trimBST(root->left , low , high);
        }
        
        if(root->val > high){
            return trimBST(root->left , low , high);
        }
        else{
            root->right = trimBST(root->right , low , high);
        }
        
        return root;
        
    }
};