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
    ListNode* removeNodes(ListNode* head) {
        
        stack<ListNode*> st;
        ListNode* temp = head;
        ListNode* prev = temp;
        
        vector<int> v;
        while(temp)
        {
            if(st.empty())
            {
                st.push(temp);
            }
            
            else
            {
                while(!st.empty() && st.top()->val < temp->val)
                {
                    st.pop();
                }
                st.push(temp);
            }
            temp = temp->next;            
        }
        
        while(!st.empty())
        {
            v.push_back(st.top()->val);
            st.pop();
        }

        reverse(v.begin() , v.end());
        ListNode* A = new ListNode(0);
        temp = A;
        for(auto it : v)
        {
            temp->next = new ListNode(it);
            temp = temp->next;
        }

        return A->next;
    }
};