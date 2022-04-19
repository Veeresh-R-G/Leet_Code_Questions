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
    vector<int> inOrder(TreeNode * root){
        if(root == NULL){
            return {};
        }
        
        vector<int> ans;
        stack<TreeNode * > st;
        TreeNode * curr = root;
        while(!st.empty() || curr!=NULL)
        {
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode * top = st.top();
            st.pop();
            ans.push_back(top->val);
            curr = top->right;
        }
        return ans;
    }
    void recoverTree(TreeNode* root) {
        
        vector<int> ans = inOrder(root);
        sort(ans.begin() , ans.end());
        int i = 0;
        
        stack<TreeNode * > st;
        TreeNode * curr = root;
        while(!st.empty() || curr!=NULL)
        {
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            TreeNode * top = st.top();
            st.pop();
            
            //business here 
            if(top->val != ans[i]){
                top->val = ans[i];
            }
            i++;
            
            curr = top->right;
        }
        
    }
};