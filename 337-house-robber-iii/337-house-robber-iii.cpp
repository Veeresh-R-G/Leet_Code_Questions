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
    
    int solve(TreeNode* root ,map<TreeNode* , int>&myMap)
    {
        if(root == NULL) return 0;
        
        if(myMap.find(root) != myMap.end()) return myMap[root];
        int pick = root->val;
        if(root->right && root->right->left) pick += solve(root->right->left , myMap);
        if(root->right && root->right->right) pick += solve(root->right->right , myMap);
        if(root->left && root->left->right) pick += solve(root->left->right , myMap);
        if(root->left && root->left->left) pick+= solve(root->left->left , myMap);
        
        int notPick = 0;
        
        if(root->right) notPick += solve(root->right , myMap);
        if(root->left) notPick += solve(root->left , myMap);
        
        return myMap[root] = max(pick , notPick);
    }
    
    int rob(TreeNode* root) {
        
        if(root == NULL) return 0;
        
        map<TreeNode* , int> myMap;
        
        return solve( root, myMap);
    }
};