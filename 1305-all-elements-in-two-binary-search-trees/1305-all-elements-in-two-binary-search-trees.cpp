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
    
    vector<int> v1;
    vector<int> v2;
    
    
    vector<int> Inorder(TreeNode* root)
    {
        if(root == NULL)
        {
            return {};
        }
        
        
        vector<int> temp;
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
            
            
            // cout << curr->val << " ";
            temp.push_back(curr->val);

            curr = curr->right;

        }
        
        return temp;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
     
            if(root1 && !(root2))
            {
                v1 = Inorder(root1);
                return v1;
            }
        
            if(!(root1) && root2)
            {
                v2 = Inorder(root2);
                return v2;
            }
        
            v1 = Inorder(root1);
            v2 = Inorder(root2);
        
            vector<int> ans;
            int i = 0;
            int j = 0;
        
        while(i < v1.size() && j < v2.size())
        {
            if(v1[i] <= v2[j])
            {
                ans.push_back(v1[i]);
                i++;
            }
            else if(v1[i] > v2[j])
            {
                ans.push_back(v2[j]);
                j++;
            }
            
        }
        
        while(i < v1.size())
        {
            ans.push_back(v1[i]);
            i++;
        }
        
        while(j < v2.size())
        {
            ans.push_back(v2[j]);
            j++;
        }
        
        return ans;
    
        
    }
};