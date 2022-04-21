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
#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL)
        {
            return {};
        }
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!(q.empty()))
        {
            long long n = q.size();
            vector <int> temp;
            for(long long i = 0 ; i < n;i++)
            {
                TreeNode* f = q.front();
                q.pop();
                temp.push_back(f->val);
                if(f->left)
                {
                    q.push(f->left);
                }
                if(f->right)
                {
                    q.push(f->right);
                }
                
            }
            v.push_back(temp);
        }
        
        reverse(v.begin(), v.end());
        
        return v;
        
        
        
    }
};