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
    vector<TreeNode*> ans;


    vector<TreeNode*> solve(int left , int right){
        if(left == right){
            return {new TreeNode(left)};
        }
        
        if(left > right){
            return {nullptr};
        }

        vector<TreeNode*> temp;

        for(int i = left ; i <= right ; i++){
            vector<TreeNode*> leftSubTree = solve(left , i - 1);
            vector<TreeNode*> rightSubTree = solve(i + 1, right);


            for(auto leftNode : leftSubTree){
                for(auto rightNode : rightSubTree){
                    TreeNode* root = new TreeNode(i , leftNode , rightNode);
                    temp.push_back(root);
                }
            }

        }

        return temp;


    }

public:
    vector<TreeNode*> generateTrees(int n) {
        

        return solve(1 , n);
    }
};