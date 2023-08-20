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
class Solution {
public:
    void reorderList(ListNode* head) {
        
        vector<int> nums;

        ListNode* temp = head;

        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> reOrder;
        int n = nums.size();
        for(int i = 0 ; i < (n / 2) ; i++){
            reOrder.push_back(nums[i]);

            reOrder.push_back(nums[n - i - 1]);
        }
        if(n % 2){
            reOrder.push_back(nums[ (n / 2) ]);
        }
    
        ListNode* tempo = head;
        for(auto it : reOrder){
            // cout << it << " ";
           tempo->val = it;
           tempo = tempo->next;
        }       

    }
};