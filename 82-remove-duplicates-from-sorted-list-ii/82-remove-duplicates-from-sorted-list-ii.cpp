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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode* t = head;
        ListNode* prev = NULL;
        while(t && t->next)
        {
            if(t->val != t->next->val)
            {
                prev = t;
                t = t->next;
            }
            else
            {
                int val = t->val;
                ListNode* temp = t->next;
                if(temp)
                {
                    while(temp && temp->val == val)
                    {
                        temp = temp->next;
                    }
                    if(prev == NULL)
                    {
                        head = temp;
                        t = head;
                    } 
                    else
                    {
                        prev->next = temp;
                        t = temp;
                    }
                        
                }               
            
            }
        }
        return head;
    }
        
        
};