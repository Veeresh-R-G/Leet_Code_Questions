/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    
    vector<TreeNode*> ans;
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)     
    {
        
         stack<TreeNode *> s;
        TreeNode *curr = cloned;
        TreeNode* ans = NULL;
        while (curr != NULL || s.empty() == false)
        {
        
            while (curr !=  NULL)
            {

                s.push(curr);
                curr = curr->left;
            }
 
       
            curr = s.top();
            s.pop();

            if(curr->val == target->val)
            {
                // cout << "IM here " << endl;
                return curr;
            }
 
        
            curr = curr->right;
 
        }
        
        return ans;
    }
       
    
};