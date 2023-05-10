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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>>ans (m , vector<int>(n , -1));
        
        ListNode* temp = head;
        
        int row = 0;
        int rowEnd = m - 1;
        int col = 0;
        int colEnd = n - 1;
        
        int count = 0;
        int total = m * n;
        
        int value = -1;
        while(temp != NULL)
        {
            for(int i = col ; temp && i <= colEnd ; i++)
            {
                value = temp->val;
                ans[row][i] = value;
                
                temp = temp->next;
               
            }
            row++;
            
            for(int i = row; temp && i <= rowEnd ;i++)
            {
                value = temp->val;
                ans[i][colEnd] = value;
                
                temp = temp->next;
            }
            colEnd--;
            
            
            for(int i = colEnd ; temp && i >= col ;i--)
            {
                value = temp->val;
                ans[rowEnd][i] = value;
                
                temp = temp->next;
                
            }
            rowEnd--;
            
            
            for(int i = rowEnd ; temp && i >= row ;i--)
            {
                value = temp->val;
                ans[i][col] = value;
                
                temp = temp->next;
            }
            col++;
        }
        
        return ans;
    }
};