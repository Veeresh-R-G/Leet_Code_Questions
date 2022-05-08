class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char , int>> st;
        
        /*
        
        Now Its Important to know Why stack anta
        
        1. We are always removing the latest consecutive k repeated string
        2.Since its the latest , stack serves the purpose of accessing the latest item
            Since its based on LIFO (or) FILO
        
        
        3. And, we will be removing the thing from the stack only when we encounter
            k consecutive string.(latest one)
        
        4. if its not consecutive we should not remove it!!
        
        so its always consecutive and the latest consecutive 'k' repeated strings
        that we will be removing !!
        
        Ok I am convinced !!
        
        */
        
        /*
        
        ------------------------------Code Explanation---------------------------------
        
        1. st.top().first == s[i]
            we are dng this to ensure that we just incrementing the current char's count
            and not some other count
            
        
        */
        int n = s.length();
        
        for(int i = 0 ; i < n ; i++)
        {
            char temp = s[i];
            
            if(!st.empty() && st.top().first == temp)
            {
                auto top = st.top();
                st.pop();
                
                st.push({top.first , top.second + 1});
            }
            else
            {
                pair<char , int> p = {temp , 1};
                st.push(p);
            }
            
            if(st.top().second == k)
            {
                st.pop();
            }
        }
        
        string ans = "";
        
        while(!st.empty())
        {
            pair<char , int> p = st.top();
            st.pop();
            
            while(p.second)
            {
                ans.push_back(p.first);
                p.second--;
            }
            
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};