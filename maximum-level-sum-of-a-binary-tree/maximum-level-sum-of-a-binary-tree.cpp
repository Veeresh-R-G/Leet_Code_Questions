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
    int maxLevelSum(TreeNode* root) {
        

        int level = 1;
        queue <TreeNode*> q;

        int ans = INT_MIN;
        int sum = INT_MIN;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            int currSum = 0;
            for(int i = 0; i < n ; i++)
            {
                auto node = q.front();
                currSum += node->val;
                q.pop();

                if(node->left)
                {
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }
            }

            if(currSum > sum)
            {
                sum = currSum;
                ans = level;
            }

            level += 1;
        }

        return ans;
    }
};