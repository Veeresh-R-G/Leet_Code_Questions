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
    int len(ListNode* head)
    {
        if(head == NULL){
            return 0;
        }
        else{
            return 1 + len(head->next);
        }
    }
    ListNode* swapNodes(ListNode* head, int k) {
        
        /* 
        
        1. k = 2
        
        2. k = 5 
        
        3. k = 1
        
        */  
        int l = len(head); // l = 5 / 10
        int from_back = l - k ;
        /* 
        
        1.from_back = 3 = ( 5 - 2)
        
        2. from_back = 10 - 5 = 5
        
        3.from_back = 10 - 1 = 9
        
        */       
        ListNode* front = head;
        ListNode* backInda = head;
        
        //k == 1
        while(k > 1){
            front = front->next; // be at 7
            k--;
        }
        
        // from_back =9
        while(from_back){
            from_back--;
            backInda = backInda->next;
        }
        
        //Swap values and escape lol
        int temp = front->val;
        front->val = backInda->val;
        backInda->val = temp;
        
        return head;
    }
};