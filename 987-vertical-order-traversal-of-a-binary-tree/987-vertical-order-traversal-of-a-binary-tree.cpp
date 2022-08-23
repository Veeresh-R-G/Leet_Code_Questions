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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<vector<int>> ans;
    if(!root)
    {
        return ans;
    }
    
    // vertical --- Level --- Elements at the level
    /*
        Why map because map sorts bascially stores like tree
        
    */
    map<int , map<int, multiset<int>>> myMap;
    
    // Queue    
    // Node --> Vertical --> Level
    queue<pair<TreeNode* , pair<int , int>>> q;
    q.push({root , {0 , 0}});
    
    while(!q.empty())
    {
        auto front = q.front();
        q.pop();
        
        int data = front.first->val;
        int vertical = front.second.first;
        int level = front.second.second;
        
        myMap[vertical][level].insert(data);
        
        if(front.first->left) q.push({front.first->left ,{vertical - 1 , level + 1}});
        if(front.first->right) q.push({front.first->right ,{vertical + 1 , level + 1}});
              
    }
    
    for(auto it : myMap)
    {
        vector<int> temp;
        //item == <level , node->data>
        for(auto items : it.second)
        {
            temp.insert(temp.end() , items.second.begin() , items.second.end());
        }
        
        ans.push_back(temp);
    }
    
    return ans;
    }
};