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
   
    vector<vector<int>> solve(TreeNode* root)
    {
        if(!root)
        {
            return {};
        }
        stack<TreeNode*> s1 , s2;
        
        s1.push(root);
        vector<vector<int>> ans;
        while(!s1.empty() || !s2.empty())
        {
            vector<int> temp;
            if(!s1.empty())
            {
                while(!s1.empty())
                {
                    TreeNode* top = s1.top();
                    s1.pop();
                    
                    temp.push_back(top->val);
                    if(top->left)
                    {
                        s2.push(top->left);
                    }
                    
                    if(top->right)
                    {
                        s2.push(top->right);
                    }
                }
            }
            else
            {
                while(!s2.empty())
                {
                    TreeNode* top = s2.top();
                    s2.pop();
                    
                    if(top->right)
                    {
                        s1.push(top->right);
                    }
                    
                    temp.push_back(top->val);
                    if(top->left)
                    {
                        s1.push(top->left);
                    }
                    
                    
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        return solve(root);
    }
};