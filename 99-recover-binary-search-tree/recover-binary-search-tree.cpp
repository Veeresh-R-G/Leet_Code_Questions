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
    vector<int> pre;
    TreeNode* first, *second;
    private:
        void solve(TreeNode* root){
            if(root == nullptr){
                return;
            }

            solve(root->left);
            pre.push_back(root->val);
            solve(root->right);
        }

        void traverse(TreeNode* root , int a , int b){
            if(root == NULL){
                return;
            }

          

            traverse(root->left , a , b);
            
            if(root->val == a){
                first = root;
            }

            if(root->val == b){
                second = root;
            }
            
           
            traverse(root->right , a , b);
        }
public:
    void recoverTree(TreeNode* root) {
        
        vector<int> temp;

        solve(root);
        temp = pre;

        sort(temp.begin() , temp.end());
        int node_1 = -1;
        int node_2 = -1;
        for(int i = 0 ; i < temp.size() ; i++){
            cout << pre[i] << " " << temp[i] << endl;
            if(temp[i] != pre[i]){
                if(node_1 == -1){
                    node_1 = temp[i];
                }
                else if(node_2 == -1){
                    node_2 = temp[i];
                }
            }
        }

        traverse(root , node_1 , node_2);
        first->val = node_2;
     
        second->val = node_1;
    }
};