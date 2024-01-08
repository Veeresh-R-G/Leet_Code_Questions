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
    int ans = 0;

    void traverse(TreeNode* root, int low, int high){
        if(root == nullptr){
            return;
        }

        if(root->val <= high && root->val >= low){
            ans += root->val;
        }

        traverse(root->left, low, high);
        traverse(root->right, low, high);

    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        traverse(root, low, high);

        return ans;
    }
};