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
    ListNode* solve(ListNode* head , int k){
        
        if(head == NULL){
            return head;
        }

        ListNode* temp = head;

        for(int i = 0 ; i < k - 1 ; i++){
            temp = temp->next;
            if(temp == nullptr){
                return head;
            } 
        }

        ListNode* prevptr = nullptr , *currptr = head , *nxtptr = nullptr;
        
        int cnt = 0;
        while(currptr != nullptr && cnt < k){
            
            nxtptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nxtptr;
            cnt++;
        }


        if(nxtptr){
            head->next = solve(nxtptr , k);
        }

        return prevptr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == nullptr || head->next == nullptr || k == 1){
            return head;
        }


        return solve(head , k);
    }
};