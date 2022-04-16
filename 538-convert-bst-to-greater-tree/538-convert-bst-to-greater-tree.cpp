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
    vector<int> inorder(TreeNode * root){
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *curr = root;
 
    while (curr != NULL || s.empty() == false)
    {
        while (curr !=  NULL)
        {            
            s.push(curr);
            curr = curr->left;
        }        
        curr = s.top();
        s.pop(); 
        ans.push_back(curr->val);
        curr = curr->right; 
    }    
        return ans;
        
}
    
    
    TreeNode* convertBST(TreeNode* root) {
        
        TreeNode* temp = root;
        if(root == NULL)
        {
            return root;
        }
        
        vector<int> ans = inorder(root);
        
        //cheked for inorder traversal peas!
        for (auto& it : ans) {
        cout << it << ' ';
        }
        int n = ans.size();
        //Now lets reverse the array --> to reduce efficiency and maintain till O(n)
        for(int i  = 0 ; i < (ans.size() / 2) ; i++){
            int temp = ans[i];
            ans[i] = ans[n - i - 1];
            ans[n - i - 1] = temp;
        }
        
        //done now we have reversed
        //so now lets proceed
        vector<int> ansReal(n , 0);
        
        ansReal[0] = ans[0];
        
        cout << endl;
        for(int i = 0 ; i < ans.size() - 1 ; i++){
            ansReal[i+1] = ansReal[i] + ans[i+1];
        }
        
        for(int i  = 0 ; i < (ansReal.size() / 2) ; i++){
            int temp = ansReal[i];
            ansReal[i] = ansReal[n - i - 1];
            ansReal[n - i - 1] = temp;
        }
        
        
        //again testing now in order madu values haku ashte done maga
        for (auto& it : ansReal) {
        cout << it << ' ';
        }
        
        stack<TreeNode *> s;
        TreeNode *curr = root;
    
        int i = 0 ;
    while (curr != NULL || s.empty() == false)
    {
       
        while (curr !=  NULL)
        {
            s.push(curr);
            curr = curr->left;        
        }
        curr = s.top();
        s.pop();
 
        curr->val = ansReal[i];
        i++;
        curr = curr->right;
 
    }
        
        return root;
    }
};