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


    bool isLeaf(TreeNode* node)
    {
        if(!node->right && !node->left)
        {
            return true;
        }

        return false;
    }

    void f(TreeNode* root , vector<int>& v)
    {
        if(!root) return;

        if(isLeaf(root))
        {
            v.push_back(root->val);     
        } 
        f(root->left , v);
        f(root->right , v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> v1 , v2;

        f(root1 , v1);
        f(root2 , v2);

        if(v1.size() != v2.size()) return false;

        int n = v1.size();

        for(int i = 0 ; i < n ; i++)
        {
            if(v1[i] != v2[i])
            {
                return false;
            }
        }

        return true;
    }
};