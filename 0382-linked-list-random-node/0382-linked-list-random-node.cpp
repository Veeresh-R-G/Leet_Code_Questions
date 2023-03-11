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
    ListNode* head;
    int len = 0;
    Solution(ListNode* head) {
        
        this->head = head;
        
        ListNode* temp = head;
        
        while(temp)
        {
            temp = temp->next;
            len++;
        }
    }
    
    int getRandom() {
        
        int rand_ind = rand() % len;
        ListNode* temp = head;;
        for(int i = 0 ; i < rand_ind ; i++)
        {
            temp = temp->next;
        }
        
        return temp->val;
       
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */