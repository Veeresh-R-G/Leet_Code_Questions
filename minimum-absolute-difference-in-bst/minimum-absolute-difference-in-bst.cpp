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
    vector<int> inOrder;

    void f(TreeNode* root)
    {
        if(root == NULL) return;

        f(root->left);
        inOrder.push_back(root->val);
        f(root->right);

    }
public:
    int getMinimumDifference(TreeNode* root) {
        

        int diff = INT_MAX;

        f(root);

        for(int i = 1 ; i < inOrder.size() ; i++)
        {
            diff = min(diff , inOrder[i] - inOrder[i - 1]);
        }

        return diff;
    }
};