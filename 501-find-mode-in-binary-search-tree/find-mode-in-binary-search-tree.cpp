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
    map<int , int> mp;

    void helper(TreeNode* root){
        if(!root){
            return;
        }

        helper(root->left);
        mp[root->val]++;
        helper(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        

        int mini = INT_MIN;
        helper(root);
        vector<int> ans;

        
        for(auto it : mp){
            if(it.second > mini){
                mini = it.second;
            }
        }
        for(auto it : mp){
            if(it.second == mini){
                ans.push_back(it.first);
            }
        }
        
        return ans;
        
    }
};