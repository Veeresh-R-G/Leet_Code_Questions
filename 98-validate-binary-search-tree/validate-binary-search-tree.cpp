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
    vector<int> order;

    void inOrder(TreeNode* root){
        if(!root){
            return;
        }

        inOrder(root->left);
        order.push_back(root->val);
        inOrder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        
        if(!root) return true;
        inOrder(root);
        int n = order.size();
        for(int i = 1 ; i < n ; i++){
            if(order[i] <= order[i - 1]){
                return false;
            }
        }

        return true;

    }
};