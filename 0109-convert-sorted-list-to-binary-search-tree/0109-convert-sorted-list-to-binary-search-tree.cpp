/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* f(vector<int> n)
    {
        int N = n.size();
        if(!N) return NULL;
        int mid = N / 2;
        
        
        vector<int> left(n.begin() , n.begin() + mid);
        vector<int> right(n.begin() + mid + 1 , n.end());
        
        return new TreeNode(n[mid] , f(left) , f(right));
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head == NULL) return NULL;
        
        
        vector<int> ans;
        
        ListNode* temp = head;
        
        while(temp)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        
        return f(ans);
        
    }
};