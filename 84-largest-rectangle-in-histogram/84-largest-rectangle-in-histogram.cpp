class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        
        
        
        int area = -10;
        
        stack<int> st;        
        
        int n = a.size();
        vector<int> l_prev(n , -1);
        vector<int> r_prev(n , -1);
        
        /* For Finding Prev Smaller element */
        for(int i = 0 ; i < n ; i++)
        {
           while(!st.empty() && a[st.top()] >= a[i])
           {
               st.pop();
           }
            
            if(st.empty()) l_prev[i] = 0;
            
            else l_prev[i] = st.top() + 1;
            
            st.push(i);
        }
        
        /* Emptying the stack...hehe xD */
        while(st.empty() == false)
        {
            st.pop();
        }
        
        /* For Finding Next Smaller element */
        for(int i = n - 1 ; i >= 0 ; i--)
        {
           while(!st.empty() && a[st.top()] >= a[i])
           {
               st.pop();
           }
            
            if(st.empty()) r_prev[i] = n - 1;
            
            else r_prev[i] = st.top() - 1;
            
            st.push(i);
        }
        
        /*  Final Loop to calculate the max Area    */
        
        for(int i = 0 ; i < n ; i++)
        {
            area = max(area , a[i] * (r_prev[i] - l_prev[i] + 1));
        }
        
        return area;
    }
};