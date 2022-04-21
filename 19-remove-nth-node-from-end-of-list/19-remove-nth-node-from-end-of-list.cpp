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
    int length(ListNode* head)
    {
        if(head == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + length(head->next);
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
        {
            return NULL;
        }
        else if(length(head) == 1)
        {
            if(n == 1)
            {
                return NULL;
            }
        }
        int size = length(head);
        int temp = size - n - 1  ; //5 - 2 = 3 - 1 = 2
        
        if(temp>=0)
        {
            ListNode* run = head;
        while((temp))
        {
            run = run -> next;
            temp = temp - 1;
        }
        if(run->next)
        {
            run->next = run->next->next;
        }
        }
        else
        {
            head = head->next;
        }
        
        return head;
    }
};