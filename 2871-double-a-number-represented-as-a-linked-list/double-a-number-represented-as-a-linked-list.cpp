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
    ListNode* rev(ListNode * head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* newHead = rev(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        
        ListNode* temp = head;

        ListNode* t1 = new ListNode(-1);
        ListNode* t2 = new ListNode(-1);
        ListNode* temp1 = t1;
        ListNode* temp2 = t2;
        while(temp){
            temp1 -> next = new ListNode(temp->val);
            temp = temp-> next;
            temp1 = temp1-> next;
        }
        temp = head;

        while(temp){
            temp2 -> next = new ListNode(temp->val);
            temp = temp-> next;
            temp2 = temp2-> next;
        }

        t1 = t1->next;
        t2 = t2->next;
       
        t1 = rev(t1);
        t2 = rev(t2);


        int carry = 0;
        int sum = 0;
        ListNode* ans = new ListNode(-1);
        ListNode* ansTemp = ans;
        while(temp1 && temp2){

            int s = temp1->val + temp2->val + carry;
            sum = s % 10;
            carry = s / 10;

            ansTemp->next = new ListNode(sum);
            ansTemp = ansTemp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1){
            int c = temp1->val + carry;
            sum = c % 10;
            carry = c / 10; 
            ansTemp -> next = new ListNode(sum);
            ansTemp = ansTemp->next;
            temp1 = temp1->next;
        }
        while(temp2){
            int c = temp2->val + carry;
            sum = c % 10;
            carry = c / 10; 
            ansTemp -> next = new ListNode(sum);
            ansTemp = ansTemp->next;
            temp2 = temp1->next;
        }

        if(carry){
            ansTemp->next = new ListNode(carry);
        }

        return rev(ans->next);


    }
};