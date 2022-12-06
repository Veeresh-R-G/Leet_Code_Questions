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
        
        ListNode* temp = head;
        ListNode* ANS = new ListNode();
        ListNode* A = ANS;
        int c = 1;

        while(temp)
        {
            if(c % 2)
            {
                ANS->next = new ListNode(temp->val);
                ANS = ANS->next;
            }
            temp = temp->next;
            c = c + 1;
        }

        temp = head;
        c = 1;
        while(temp)
        {
            if(c % 2 == 0)
            {
                ANS->next = new ListNode(temp->val);
                ANS = ANS->next;
            }
            temp = temp->next;
            c = c + 1;
        }
        return A->next;
    }
};