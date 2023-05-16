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

    ListNode* swapPairs(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* temp = head;
        ListNode* first = temp;
        ListNode* second = temp;
        ListNode* nexto = temp;
        ListNode* prev = temp;
        
        ListNode* ans = head->next; // second node
        while(temp && temp->next != NULL)
        {
            
            first = temp;
            second = temp->next;
            nexto = second->next;
            first->next = nexto;
            second->next = first;
            temp = nexto;
            if(first != head)
            {
                prev->next = second;
            }
            prev = first; // second->next
        }

        return ans;
        

    }
};