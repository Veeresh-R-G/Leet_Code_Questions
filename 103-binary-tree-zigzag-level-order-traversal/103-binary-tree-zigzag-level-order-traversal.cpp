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
#include <stack>
#include <vector>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root== NULL)
        {
            return {};
        }
        vector<vector<int>> v;
        stack<TreeNode*> s1; // l to r
        stack<TreeNode*> s2; // r to l
        s1.push(root); // Root is always being read from left to right; thats why 
        //we store in s1
        
        while(!(s1.empty()) || !s2.empty())
        {
            vector<int> temp;
            if(!(s1.empty()))
            {
                while(!(s1.empty()))
                {
                    TreeNode* front = s1.top();
                    temp.push_back(front->val);
                    s1.pop();
                    if(front->left)
                    {
                        s2.push(front->left);
                    }
                    if(front->right)
                    {
                        s2.push(front->right);
                    }
                }
                
            }
            else
            {
                while(!(s2.empty()))
                {
                    TreeNode* front = s2.top();
                    temp.push_back(front->val);
                    s2.pop();
                    
                    if(front->right)
                    {
                        s1.push(front->right);
                    }
                    if(front->left)
                    {
                        s1.push(front->left);
                    }
                }
                    
            }
            v.push_back(temp);
        }
        return v;
    }
};