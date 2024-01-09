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
    void leafSeq(TreeNode* root, vector<int>& v){
        if(root == nullptr){
            return;
        }
        
        if(root->left == nullptr && root->right == nullptr){
            
            v.push_back(root->val);
            return;
        }

        leafSeq(root->left, v);
        leafSeq(root->right, v);

    }

    bool isEqual(vector<int>& t1, vector<int>& t2){

        if(t1.size() != t2.size()){
            return false;
        }

        for(int i = 0 ; i < t1.size(); i++){
            cout << t1[i] << " " << t2[i] << endl;
            if(t1[i] != t2[i]){
                return false;
            }
        }

        return true;
    }

    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> t1, t2;

        leafSeq(root1, t1);
        leafSeq(root2, t2);

        return isEqual(t1, t2);
    }
};