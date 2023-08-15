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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* lessThanX = new ListNode(-1);
        ListNode* greaterThanX = new ListNode(-1);

        ListNode* temp = head;
        ListNode* temp1 = lessThanX;
        ListNode* temp2 = greaterThanX;
        ListNode* prevptr = nullptr;
        while(temp){
            if(temp->val < x){
                prevptr = temp1;
                temp1 -> next = new ListNode(temp->val);
                temp1 = temp1 -> next;
            }

            if(temp -> val >= x){
                temp2 -> next = new ListNode(temp -> val);
                temp2 = temp2->next;
            }

            temp = temp->next;
        }

        temp1->next = greaterThanX->next;

        return lessThanX->next;


    }
};