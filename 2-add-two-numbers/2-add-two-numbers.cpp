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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode * temp1 = l1;
            ListNode * temp2 = l2;
            ListNode * ansHead = new ListNode(-1);
            ListNode* temp = ansHead;
            int sum = 0;
            int carry = 0;
            while(temp1 && temp2)
            {
                sum = (temp1->val + temp2->val + carry) % 10;
                carry = (temp1->val + temp2->val + carry) / 10;
                
                temp->next = new ListNode(sum);
                temp = temp->next;
                temp1 = temp1->next;
                temp2 = temp2->next;
                
            }
            
            if(temp1)
            {
                while(temp1)
                {
                    sum = (temp1->val + carry) % 10;
                    carry = (temp1->val + carry) / 10; 
                    temp->next = new ListNode(sum);
                    temp = temp->next;
                    temp1 = temp1->next;
                }
            }
        
            if(temp2)
            {
                while(temp2)
                {
                    sum = (temp2->val + carry) % 10;
                    carry = (temp2->val + carry) / 10; 
                    temp->next = new ListNode(sum);
                    temp = temp->next;
                    temp2 = temp2->next;
                }
            }
            
            if(carry)
            {
                temp->next = new ListNode(carry);
                temp = temp->next;
            }
            
            ansHead = ansHead->next;
            return ansHead;
        
            
    }
};