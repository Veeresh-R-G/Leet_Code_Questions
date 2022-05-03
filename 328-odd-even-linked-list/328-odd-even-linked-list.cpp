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
    ListNode* oddEvenList(ListNode* head) {
        
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        /*
            Time : O(n)
            Space : O(1)
            
        */
        ListNode* ans = new ListNode(-1);
                
        
        ListNode* even = new ListNode(-1);
        ListNode* e = even;
        
        
        ListNode* odd = new ListNode(-1);
        ListNode* o = odd;
        
        ListNode* temp;
        temp = head;
        
        
        while(temp!=NULL)
        {
            odd->next = new ListNode(temp->val);
            odd = odd ->next;
            if(temp->next)
            {
                temp = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
            
        }
        
        
        temp = head->next;
        while(temp!=NULL)
        {
            even->next = new ListNode(temp->val);
            even = even ->next;
            if(temp->next)
            {
                temp = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
            
        }
        
        odd->next = e->next;
        ans->next = o->next;
        ans = ans->next;
        return ans;
    }
};