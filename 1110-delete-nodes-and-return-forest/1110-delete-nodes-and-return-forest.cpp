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
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    
    bool isDel(int key , vector<int>& v)
    {
        std::vector<int>::iterator it;
        it = std::find (v.begin(), v.end(), key);
        if(it == v.end())
        {
            return false;
        }
        
        return true;
    }
    TreeNode* f(TreeNode* root, vector<int>& to_delete , vector<TreeNode*>& ans)
    {
        if(!root) return root;
        
        
        root->left = f(root->left , to_delete , ans);
        root->right = f(root->right , to_delete , ans);
        
        if(isDel(root->val , to_delete))
        {
            if(root->left)
            {
                ans.push_back(root->left);
            }
            if(root->right)
            {
                ans.push_back(root->right);
            }
            
            return NULL;
        }
        
        return root;
        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> ans;
        
        
        f(root , to_delete , ans);
       
        if(!isDel(root->val , to_delete))  ans.push_back(root);
        return ans;
    }
};