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
    
    vector<int> inOrder(TreeNode* root)
    {
        if(root == NULL)
        {
            return {};
        }
        
        stack<TreeNode*> st;
        TreeNode* node = root;
    
        vector<int> ans;
        
        while(true)
        {
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if(st.empty()) break;
                TreeNode* top = st.top();
                st.pop();
                
                ans.push_back(top->val);
                
                node = top->right;
            }
           
        }
        
        return ans;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        return inOrder(root);
    }
};