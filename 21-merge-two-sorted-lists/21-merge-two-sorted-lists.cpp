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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        
        ListNode* ansHead = new ListNode(-1);
        ListNode* temp = ansHead;
        
        while(t1 && t2)
        {
            if(t1->val >= t2->val)
            {
                temp->next = new ListNode(t2->val);
                temp = temp->next;
                t2 = t2->next;
            }
            else
            {
                temp->next = new ListNode(t1->val);
                temp = temp->next;
                t1 = t1->next;
            }
        }
        
        if(t1)
        {
            temp->next = t1;
        }
        if(t2)
        {
            temp->next = t2;
        }
        
        return ansHead->next;
    }
};