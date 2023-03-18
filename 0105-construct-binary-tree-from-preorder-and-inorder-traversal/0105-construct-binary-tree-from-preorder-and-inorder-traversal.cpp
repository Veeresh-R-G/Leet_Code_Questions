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
    
    TreeNode* helper(vector<int>& preorder ,unordered_map<int , int>& umap , int& rootInd , int start , int end)
    {
        if(start > end || start >= preorder.size()) return NULL;
        
        
        TreeNode* root = new TreeNode(preorder[rootInd]);
        int pivot = umap[preorder[rootInd]];
        rootInd++;
        root->left = helper(preorder , umap , rootInd , start , pivot - 1);
        root->right = helper(preorder , umap , rootInd , pivot + 1 , end );
            
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        unordered_map<int , int> umap;
        
        for(int i = 0 ; i < inorder.size() ; i++)
        {
            umap[inorder[i]] = i;
        }
        int rootInd = 0;
        return helper(preorder ,umap , rootInd , 0 , inorder.size() - 1);
    }
};