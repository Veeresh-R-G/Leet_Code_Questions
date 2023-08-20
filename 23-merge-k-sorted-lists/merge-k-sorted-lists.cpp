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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> nums;
        for(auto it : lists){
            ListNode* temp = it;

            while(temp){
                nums.push_back(temp->val);
                temp = temp->next;
            }
        }

        sort(nums.begin() , nums.end());

        ListNode* ans = new ListNode(-1);
        ListNode* t = ans;

        for(auto it : nums){
            t -> next = new ListNode(it);
            t = t -> next;
        }

        return ans->next;
    }
};