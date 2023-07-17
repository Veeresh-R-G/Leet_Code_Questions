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

    private:
        ListNode* revList(ListNode* head)
        {
            if(head == NULL || head->next == NULL)
            {
                return head;
            }

            ListNode* newHead = revList(head->next);
            head->next->next = head;
            head->next = NULL;
            return newHead;
        }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = revList(l1);
        l2 = revList(l2);

        
        ListNode* t1 = l1;
        ListNode* t2 = l2;

        
        //final answer list
        ListNode* ans = new ListNode(-1);
        ListNode* t3 = ans;
        int sum = 0;
        int carry = 0;

        while(t1 && t2)
        {

            int num1 = t1->val;
            int num2 = t2->val;

            sum = (carry + num1 + num2) % 10;
            carry = (carry + num1 + num2) / 10;
            
            t3->next = new ListNode(sum);
            t3 = t3->next;

            t1 = t1->next;
            t2 = t2->next;
        }

        while(t1)
        {
            int num1 = t1->val;
            sum = (carry + num1) % 10;
            carry = (carry + num1) / 10;

            t3->next = new ListNode(sum);
            t3 = t3->next;

            t1 = t1->next;
        }
        while(t2)
        {
            int num1 = t2->val;
            sum = (carry + num1) % 10;
            carry = (carry + num1) / 10;

            t3->next = new ListNode(sum);
            t3 = t3->next;

            t2 = t2->next;
        }
        if(carry)
        {
            t3->next = new ListNode(carry);
            t3 = t3->next;
        }
        return revList(ans->next);
    }
};