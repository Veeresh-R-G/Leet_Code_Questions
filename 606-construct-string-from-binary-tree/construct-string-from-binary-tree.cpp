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
    void helper(TreeNode* root, string& ans){

        if(!root){
            return;
        }

        string temp = to_string(root->val);
        ans += temp;
        //Not to avoid the 1-1 mapping if the left node is null
        
        if(root->left || root->right){
            ans += "(";
            helper(root->left, ans);
            ans += ")";
        }

        if(root->right){
            ans += "(";
            helper(root->right, ans);
            ans += ")";
        }
    }
public:
    string tree2str(TreeNode* root) {
        
        string ans = "";

        

        helper(root,ans);
        return ans;
    
    }
};