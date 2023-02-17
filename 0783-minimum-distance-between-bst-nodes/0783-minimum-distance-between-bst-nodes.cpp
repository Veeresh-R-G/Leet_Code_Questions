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
    int mini = INT_MAX;
    vector<int> f(TreeNode* root)
        {
            if(!root->left && !root->right)
            {
                return {root->val , root->val};
            }
            
            vector<int>  leftVals = {root->val , root->val}
            , rightVals = {root->val , root->val};
            
            if(root->left)
            {
                leftVals = f(root->left);
                mini = min(mini , abs(leftVals[1] - root->val));
            }
            
            if(root->right)
            {
                rightVals = f(root->right);
                mini = min(mini , abs(rightVals[0] - root->val));
            }
            
            return {leftVals[0] , rightVals[1]};
        }
    int minDiffInBST(TreeNode* root) {       
        f(root);
        return mini;
    }
};