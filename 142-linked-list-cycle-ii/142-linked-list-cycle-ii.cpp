/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }
        else if(head->next == head)
        {
            return head;
        }
        bool cycle = false;
        ListNode* slow= head;
        ListNode* fast = head;
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                cycle = true;
                ListNode* t1 = head;
                while(t1 != slow)
                {
                    t1 = t1->next;
                    slow = slow->next;
                }
                return t1;
            }
        }
        return NULL;
    }
};