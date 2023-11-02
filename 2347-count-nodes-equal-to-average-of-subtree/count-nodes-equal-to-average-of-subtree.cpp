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
    int count = 0;

    //{sum , count of nodes}
    pair<int , int> helper(TreeNode* root){
        if(!root){
            return {0 , 0};
        }

        pair<int , int> left = helper(root->left);
        pair<int , int> right = helper(root->right);

        int sum = root->val + left.first + right.first;
        int avg = sum / (left.second + right.second + 1);


        if(avg == root->val){
            count++;
        } 

        return {sum , left.second + right.second + 1};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        
        helper(root);
        return count;
    }
};