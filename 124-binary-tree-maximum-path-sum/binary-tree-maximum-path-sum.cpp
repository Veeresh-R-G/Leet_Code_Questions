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

private:
    int f(TreeNode* root , int& ans){

        if(!root){
            return 0;
        }

        int left = max(f(root->left , ans) , 0);
        int right = max(f(root->right , ans) , 0);

        ans = max(ans , root->val + left  + right);

        return root->val + max(left , right);

    }
public:
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;

        f(root , ans);

        return ans;
    }
};