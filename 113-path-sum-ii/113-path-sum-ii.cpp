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
    
    void f(TreeNode* root , int targetSum ,vector<vector<int>>& ans , vector<int>& temp , int & s)
    {   
        if(!root) return;
        if(!root->left && !root->right)
        {   
            if((s + root->val) == targetSum)
            {   
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
            return;
            
        }
        
        temp.push_back(root->val);
        s = s + root->val;
        f(root->left , targetSum , ans , temp , s);
    
        f(root->right , targetSum , ans , temp , s);
        s = s - root->val;
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        int s = 0;
        f(root , targetSum , ans , temp , s);
        if(!root) return {};
        return ans;
    }
};