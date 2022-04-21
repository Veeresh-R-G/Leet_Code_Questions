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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            //is there is only 1 node --> i should delete 0 / 2 == 0th pos
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;
        while(slow && fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;            
        }
        if(prev->next)
        prev->next = prev->next->next;
  return head;  }
};