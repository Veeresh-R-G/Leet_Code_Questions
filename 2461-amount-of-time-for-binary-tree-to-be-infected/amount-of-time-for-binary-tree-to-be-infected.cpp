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

unordered_map<int, vector<int>> graph;

void dfs(TreeNode* root){
    if(root == nullptr){
        return;
    }

    if(root->left){
        graph[root->val].push_back(root->left->val);
        graph[root->left->val].push_back(root->val);
    }

    if(root->right){
        graph[root->val].push_back(root->right->val);
        graph[root->right->val].push_back(root->val);
    }

    dfs(root->left);
    dfs(root->right);
}

public:
    int amountOfTime(TreeNode* root, int start) {
        
        //for start node iits 0 seconds
        //so after doing the start node, it becomes 0 secs
        int ans = -1;
        dfs(root);
        
       

        queue<int> q;
        q.push(start);
        unordered_set<int> visited;
        visited.insert(start);

        while(!q.empty()){
            int n = q.size();

            for(int i =0; i < n; i++){

                auto top = q.front();
                q.pop();

                for(auto child: graph[top]){
                    if(visited.find(child) == visited.end()){
                        q.push(child);
                        visited.insert(child);
                        
                    }
                }
            }
            ans++;
        }

        return ans;




    }
};