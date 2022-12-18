class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        
        int n = temps.size();
        
        /*
            Stack stores the last index of increased Temp
        */
        stack<int> st;
        
        vector<int> ans(n , 0);
        
        for(int i = 0 ; i < n ; i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && temps[st.top()] < temps[i])
                {
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
                
                st.push(i);
            }
        }
        
        return ans;
        
    }
};