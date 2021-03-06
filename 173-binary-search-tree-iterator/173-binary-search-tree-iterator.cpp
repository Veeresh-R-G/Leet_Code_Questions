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

/*

Approach 1:
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
    
    BSTIterator(TreeNode* root) {
        //Lowest Number is 0 
        // root = new TreeNode(0);
        this->ans = inOrder(root);
        sort(ans.begin(), ans.end(), greater<int>());
    }
    
    int next() {
        
        int temp;
        temp = this->ans[this->ans.size() - 1];
        this->ans.pop_back();
        return temp;
            
        
    }
    
    bool hasNext() {
        if(this->ans.size() != 0){
            return true;
        }
        return false;
    }

*/

//Now optimised approach
class BSTIterator {
    stack<TreeNode*> st;
public:
    
    BSTIterator(TreeNode* root) {
        
        TreeNode* curr = root;
        
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        
        TreeNode* top = st.top();
        st.pop();
        
        if(top->right)
        {
            TreeNode * temp = (top->right);
            while(temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }
        }
        
        return top->val;
    }
    
    bool hasNext() {
        return st.empty() == true ? false: true; 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */