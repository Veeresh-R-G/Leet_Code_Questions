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
#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
        {
            return {};
        }
        
        queue<TreeNode*> q;
        
        q.push(root);
        vector<vector<int>> v;
        while(!(q.empty()))
        {           
            vector<int> temp;   
            int n = q.size();
            for(int i = 0 ;i < n ; i++)
            {
                TreeNode* front = q.front();
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
                q.pop();
                temp.push_back(front->val);
            }
            v.push_back(temp);
            
        }
        return v;
    }
};