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
    
    
    TreeNode* ans;
    void preOrder(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if(original != NULL)
        {
            if(original == target)
            {
                ans = cloned;
                return;
            }
            preOrder(original->left , cloned->left , target);
            preOrder(original->right , cloned->right,target);
        }
    }
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)     
    {
        
        
        preOrder(original , cloned , target);
        
        /*
        
        ----------------Appraoch - 1 --------------------------------------------
            
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
        */
        return ans;
    }
       
    
};