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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
        {
            return head;
        }
        vector<int> temp;
        
        ListNode* H = head;
        
        while(H)
        {
            temp.push_back(H->val);
            H = H->next;
        }
        
        int nodes = temp.size();
        
        k = k % nodes;
        
        vector<int>rotated(nodes  , 0);
        
        for(int i = k ; i < nodes ;i++)
        {
            rotated[i] = temp[i - k];
        }
        
        for(int i = 0 ; i < k ; i++)
        {
            rotated[i] = temp[nodes - k + i];
        }
        
        ListNode* ANS = new ListNode();
        ListNode* a = ANS;
        for(auto it : rotated)
        {
            ANS->next = new ListNode(it);
            ANS = ANS->next;
        }
        
        return a->next;
    }
};