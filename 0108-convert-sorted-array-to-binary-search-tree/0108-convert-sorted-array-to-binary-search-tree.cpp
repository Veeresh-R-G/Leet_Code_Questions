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
    
    

    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        
        int N = nums.size();
        if(!N) return NULL;
        
        int mid = N / 2;
        
        vector<int> tempLeft(nums.begin() , nums.begin() + mid);
        // for(auto it : tempLeft) cout << it << " ";
        // cout << endl;
        
        
        vector<int> tempRight(nums.begin() + mid + 1 , nums.end());
        // for(auto it : tempRight) cout << it << " ";
        // cout <<endl;
        
        return new TreeNode(nums[mid] , sortedArrayToBST(tempLeft) , sortedArrayToBST(tempRight));
            
        
    }
};