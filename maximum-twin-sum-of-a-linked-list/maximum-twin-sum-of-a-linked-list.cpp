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

    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;

    }

public:
    int pairSum(ListNode* head) {
        
        //Brute force : Store in List and return max

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(slow && fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = reverse(slow);
        prev = prev -> next;

        int ans = INT_MIN;
        slow = head;

        while(prev != NULL)
        {
            ans = max(ans , slow->val + prev->val);
            slow = slow->next;
            prev = prev->next;
        }      
          
        return ans;

    }
};