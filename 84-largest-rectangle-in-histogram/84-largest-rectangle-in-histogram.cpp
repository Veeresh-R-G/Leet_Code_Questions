class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
     
        
        
        stack<int> st;
        int area = -10;
        int n = h.size();
        for(int i = 0 ; i <= n ; i++)
        {
            while(!st.empty() &&(i == n ||  h[st.top()] >= h[i]))
            {
                int ind = st.top();
               
                
                int height = h[ind];
                st.pop();
                int rs = i;
                
                //after popping so it will be a different value !!!
                int ls = st.empty() ? 0 : st.top();
                
                int width = st.empty() ? rs : rs - ls - 1; 
                
                area = max(area , width * height);
                
                
            }
            
            
            st.push(i);
            
        }
        
        return area;
        
    }
};