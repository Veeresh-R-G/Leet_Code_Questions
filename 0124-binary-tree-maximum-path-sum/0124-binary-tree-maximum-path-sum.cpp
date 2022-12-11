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
    
    int f(TreeNode* root , int& ans)
    {
        if(!root) return 0;
        
        int leftPath = f(root->left ,ans);
        int rightPath = f(root->right , ans);
        
        cout << root->val << " " << leftPath << " " << rightPath << endl;
        /*
            ans = INT_MIN --> 2 --> 3 --> 1 + 2 + 3 ans will return 4
        
            ans = 9 --> 15  --> 20 + 15 + 7
        */

        ans = max(ans , max(root->val + leftPath + rightPath ,max(root->val , max(root->val + rightPath , root->val + leftPath))));
        cout << "ANS = " <<ans << endl;
        // if((root->val + leftPath , rightPath))
        
        return max(max(root->val + leftPath , root->val + rightPath) , root->val);

    }
    
    
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        f(root , ans);
        
        
        return ans;
    }
};